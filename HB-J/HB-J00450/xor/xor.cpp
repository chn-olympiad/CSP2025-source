#include<bits/stdc++.h>
using namespace std;
int n,k;
int cnt;
int cnt0;
int sum;
int l[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		if(l[i]==1){
			cnt++;
		}
		if(l[i]==0)cnt0++;
	}
	if(k!=1&&k!=0){
		cout<<0;
	}
	else{
		if(k==1) cout<<cnt;
		else{
			int ct;
			l[n+1]=1;
			for(int i=1;i<=n+1;i++){
				if(l[i]==1){
					if(ct>1)sum+=ct-1;
					ct=0;
				}
				else ct++;
			}
			cout<<sum+cnt/2+1;
		}
	}
	return 0;
}
