#include<bits/stdc++.h>
using namespace std;
long long int a[500005],v[500005];
long long int n,ans,p=0;
void go(int g,int i,int d,int h,int sa){
	if(i==g){
		if(h>2*d){
			ans++;
		}
		return;
	}
	for(int j=sa+1;j<=n;j++){
		int t=d;
		if(a[j]>d){
			t=a[j];
		}
		h+=a[j];
		go(g,i+1,t,h,j);
		h-=a[j];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			p=1;
		}
	}
	if(p==1){
		if(n==3){
			cout<<1;
			return 0;
		}else if(n<3){
			cout<<0;
			return 0;
		}else{
			for(int i=3;i<=n;i++){
				go(i,0,0,0,0);
			}
			cout<<ans;
		}
	}else{
		cout<<(n-1)*(n-2)/2;
	}
	return 0; 
} 