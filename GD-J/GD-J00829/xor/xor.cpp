#include<bits/stdc++.h>
using namespace std;
long long num[500005],n,k,tn,ans,vis[500005],cal;
bool flag01=true,nxt;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		if(num[i]>1) flag01=false;
		if(num[i]==1 and !flag01) tn++;
	}
	if(flag01){
		if(k){
			cout<<tn;
			return 0;
		}
		else{
			for(int i=1;i<=n;i++){
				if(num[i]==0) ans++;
				else if(num[i]==num[i+1]){
					ans++;
					i++;
				}
			}
		}
	}else{
		if(!k){
			for(int i=1;i<=n;i++){
				if(num[i]==0) ans++;
				else if(num[i]==num[i+1]){
					ans++;
					i++;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(vis[i]) continue;
				cal=num[i];
				if(cal==k){
					ans++;
					vis[i]=1;
				}
				else{
					for(int j=i+1;j<=n;j++){
						if(num[j]==k){
							ans++;
							for(int k=i;k<=j;k++) vis[k]=1;
							break;
						}
						cal=cal^num[j];
						if(cal==k){
							ans++;
							for(int k=i;k<=j;k++) vis[k]=1;
							break;
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
