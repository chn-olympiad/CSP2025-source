#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll s[500500],n,k;
struct num{
	ll sum,x,y;
};
num a[500500];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		s[i]=s[i-1]+x;
	}
	if(k!=0&&k!=1){
		
		int m=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<i;j++){
				if((s[i]-s[j])%k==0&&(s[i]-s[j])>=k){
					a[m].x=i;
					a[m].y=j;
					a[m].sum=(s[i]-s[j]);
					m++;
				}
			}
		}
		int e=0,ssum=0;
		for(int i=1;i<m;i++){
			if(a[i].sum%k==0&&a[i].y>=e){
				ssum++;
				e=a[i].x;
			}
		}
		cout<<ssum;
	}
	else{
		int ssum=0;
		for(int i=1;i<=n;i++){
			if(s[i]-s[i-1]==k){
				ssum++;
			}
		}
		cout<<ssum;
	}
	return 0; 
}
