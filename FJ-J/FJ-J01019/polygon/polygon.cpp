#include<bits/stdc++.h>
using namespace std;
int n,c=0,s=0,ans=0,a[5005];
bool b[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=5000;j++){
			b[i]==0;
		}
		int maxn=-1;
		for(int j=1;c!=0;j++){
			if(!b[j]){
				s+=a[j];
				maxn=max(maxn,a[j]);
				b[j]=!b[j];
				c--;
			}
		}
		if(s>maxn){
			ans++;
		}
	}
	cout<<ans%998244353;
	
	return 0;
}
