#include<bits/stdc++.h>
using namespace std;

int num(int h){
	long long cnt=0;
	for(int i=h-1;i>=1;i--){
		cnt+=(i+1)*i/2;
	}
	cnt+=h;
	return cnt;
}
dp(int k,int f,int a[]){
	long long s=0;
	for(int i=k+1;i<=f-1;i++){
		for(int j=i+1;j<=f;j++){
			if(a[i]+a[j]>a[k]){
				s+=num(f-j)+1;
				continue;
			}
			else{
				int ff=a[i]+a[j];
				for(int l=j+1;l<=f;l++){
					ff+=a[l];
					if(ff>a[k]){
						s+=num(f-l)+1;
						continue;
					}
				}
			}
		}
	}
	return s;
}
bool cmt(int a,int b){
	return a>b;
}
int n,a[5005];
long long ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmt);
	if(n==3&&a[1]<a[2]+a[3]){
		cout<<1;
		return 0;
	}
	if(a[n-2]<a[n-1]+a[n]){
		ans+=1;
	}
	for(int i=1;i<n-2;i++){
		ans+=dp(i,n,a);
	}
	ans%=998244353;
	cout<<ans;
	return 0;
}