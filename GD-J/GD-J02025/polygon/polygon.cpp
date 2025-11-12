#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0,b[5005],maxx=-1;
bool cmp(int a,int b){
	return a<b;
}
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n;
	b[1]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i-1];
		maxx=max(a[i],maxx);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n+1;i++){
		b[i]=b[i-1]+a[i-1];
	}
	for(int i=2;i<=n+1;i++){
		if(b[i]>a[i-1]*2){
			ans++;
			int jd=0;
			for(int j=i-2;j>=1;j--){
				if(b[i]-b[j]>a[i-1]*2){
					ans++;
					ans+=(1+j-1)/2*(j-1)-1;
					b[i]-=a[j];
					jd+=a[j];
				}
			}
			b[i]+=jd;
		}
	}
	cout<<ans%998244353<<"\n";
}
