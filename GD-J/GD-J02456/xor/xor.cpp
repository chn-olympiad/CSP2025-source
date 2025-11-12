#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
bool vis[N];
int a[N];
int op;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum=0;
			for(int c=i;c<=j;c++){
				if(vis[c]){
					break;
				}
				vis[c]=true;
				sum^=a[c];
			}
			if(sum==k && !op){
				cnt++;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
/*
4 2
2 1 0 3
4 0
2 1 0 3
4 3
2 1 0 3
*/
