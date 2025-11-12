#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int num[500010]={};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>num[i];
	for(int i=1;i<=n;i++){
		int tmp=num[i];
		int j;
		for(j=i+1;j<=n;j++){
			if(tmp==k){
				ans++;
				i=j;
				j+=1;
				tmp=num[i];
				continue;
			}
			tmp^=num[j];
		}
		if(tmp==k){
			ans++;
			break;
		}
	}cout<<ans;
	return 0;
} 
