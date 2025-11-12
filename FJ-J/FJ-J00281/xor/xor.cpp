#include<bits/stdc++.h>
using namespace std;
const int MAXX=5e5+10;
int n,k,a[MAXX],p,ans;
bool b[MAXX];
struct cal{
	int l,r;
}an[MAXX];
int xo(int x){
	int t=x,ansx=a[x];
	while(t<=n&&ansx!=k){
		t++;
		ansx=ansx^a[t];
	}
	if(ansx==k) return t;
	return 0;
}
bool check(int x,int y){
	for(int i=1;i<=x;i++)
		for(int j=x;j<=n;j++)
			if(b[i]&&b[j]){
				return 0;
			}
	for(int i=1;i<=y;i++)
		for(int j=y;j<=n;j++)
			if(b[i]&&b[j]){
				return 0;
			}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int j=xo(i);
		if(j&&check(i,j)){
			b[i]=1;
			b[j]=1;
			ans++;
		}
	}
	printf("%d",ans);
	for(int i=1;i<=n;i++)
		printf(" %d",b[i]);
	for(int i=1;i<=n;i++)
		printf(" %d",xo(i));
	return 0;
}