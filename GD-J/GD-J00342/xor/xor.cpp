#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],m,s,x,f;
struct nood{
	int x,y;
};
nood b[500005];
bool cmp(nood a,nood b){
	return a.y<b.y||a.y==b.y&&a.x<b.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);x=0;f=0;
		for(int j=i;j>=1;j--)
		{
			x^=a[j];
			if(x==k){
				b[++m].x=j,b[m].y=i;
				f=1;break;
			}
		}
	}
	if(m==0){
		cout<<0;return 0;
	}
	sort(b+1,b+1+m,cmp);x=b[1].y;s=1;
	for(int i=2;i<=m;i++)
	{
		if(b[i].x>x)s++,x=b[i].y;
	}
	printf("%d",s);
	return 0;
}
