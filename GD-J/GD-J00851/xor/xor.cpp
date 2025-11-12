#include<bits/stdc++.h>
using namespace std;
const int M=5*1e5+5;
int n,b[M],k,a[M],mi;
long long cnt,an;
struct node{
	int x,y;
}ans[10*M];
bool cmp(node anss,node ansa){
	if(anss.x!=ansa.x) return anss.x<ansa.x;
	return anss.y<ansa.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
    	b[i]=a[i]^b[i-1];
	}
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((b[j]^b[i])==k) ans[++cnt].x=i,ans[cnt].y=j;
		}
	}
	an=cnt;
	sort(ans+1,ans+cnt+1,cmp);
	for(int i=1;i<cnt;i++){
		if(ans[i].y>=ans[i+1].x && ans[i].y>=ans[i+1].y) an--;
		else if(ans[i].y>ans[i+1].x && ans[i].y<=ans[i+1].y){
		    an--;
		    ans[i+1].y=ans[i].y;
		}
	}
	if(ans[1].x==0 && ans[1].y==0) an--;
	printf("%lld",an);
	return 0;
}
