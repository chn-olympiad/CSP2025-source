#include<bits/stdc++.h>
using namespace std;
int n,k;
long long k1[500005],cnt;
bool vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>k1[i];
	}
	for(int len=0;len<=n;len++){
		for(int i=1;i+len<=n;i++){
			if(i==i+len&&vis[i]==0&&k1[i]==k){
				cnt++;
				vis[i]=1;
				continue;
			}
			int ji=0;
			for(int j=i;j<=i+len;j++){
				if(vis[j]==1){
					ji=1;
					break;
				}
			}
			if(ji==1){
				continue;
			}
			int b=k1[i];
			for(int j=i+1;j<=i+len;j++){
				b^=k1[j];
			}
			if(b==k){
				cnt++;
				for(int j=i+1;j<=i+len;j++){
					vis[j]=1;
			    }
			}
		}
	}
	cout<<cnt;
	return 0;
}
