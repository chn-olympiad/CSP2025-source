#include<bits/stdc++.h>
using namespace std;
int a[500010];
bool vis[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	int maxx=0;
	for(int x=1;x<=n;x++){
		int cnt=0;
		for(int i=x;i<=n;i++){
			for(int j=i;j<=n;j++){
				int sum=0;
				bool flag=1;
				for(int h=i;h<=j;h++){
					sum^=a[h];
					if(vis[h]){
						flag=0;
						break;
					}
				}
				if(sum==k&&flag){
					cnt++;
					for(int h=i;h<=j;h++){
						vis[h]=1;
					}
				}
			}
		}
		maxx=max(maxx,cnt);
		memset(vis,0,sizeof(vis));
	}
	printf("%d",maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
