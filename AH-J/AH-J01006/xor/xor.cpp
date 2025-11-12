#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[500010],x[500010];
bool vis[500010],l[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		
		for(int j=i;j<=n;j++){
			int yi=0,ok=0;
			for(int k=i;k<=j;k++){
				if(vis[k]){
					ok=1;
					break;
				 }
				yi^=a[k];
			}
			if(yi==k&&!ok){
				cnt++;
				for(int k=i;k<=j;k++){
					vis[k]=true;
				}
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
