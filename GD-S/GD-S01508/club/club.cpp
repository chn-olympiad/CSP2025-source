#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll t,a[100000+10],b[100000+10],c[100000+10],ans=0,aaa=0,n,ma=0;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(ll i=1;i<=t;i++){
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1,cmp);
		for(ll i=1;i<=n;i++){
			if(aaa<=n/2){
				ans+=a[i];
				aaa++;
			}
		}
	 	ma=max(ma,ans);
	}
	cout<<ma<<endl;
	cout<<0<<endl;
	cout<<0<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
