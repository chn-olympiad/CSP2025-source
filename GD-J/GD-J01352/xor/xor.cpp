#include<bits/stdc++.h>
using namespace std;
int yihuo(int x,int y){
//手打异或(不知道异或的函数www)
 int a[25],b[25],c[25],n=0,m=0,k=1,ans=0;
 memset(a,0,sizeof(a));//我写的什么狗屎缩进 
	memset(b,0,sizeof(b));
	for(int i=x;i>0;i=i/2)a[++n]=i%2;
	for(int i=y;i>0;i=i/2)b[++m]=i%2;
	for(int i=1;i<=max(n,m);i++)
		if(b[i]!=a[i])
			c[i]=1;
		else
			c[i]=0;
	for(int i=1;i<=max(n,m)/2;i++)
		swap(c[i],c[n-i+1]);
	for(int i=1;i<=max(n,m);i++,k=k*2)
		ans=ans+k*c[i];
	return ans;
}
int n,m,k,a[500005],s[1005][1005],ans=1,k1;
struct ff{
	int x,y;
}b[500005];
bool cmp(ff a,ff b){
	if(a.y!=b.y)
		return a.y<b.y;
	return (a.y-a.x)<(b.y-b.x);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i][i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j>i)
				s[i][j]=yihuo(s[i][j-1],a[j]);	
			if(s[i][j]==k)
				b[++m].x=i,b[m].y=j;
		}
	}
	sort(b+1,b+m+1,cmp);
	k1=b[1].y; 
	for(int i=2;i<=m;i++){
		if(k1<b[i].x){
			ans++,k1=b[i].y;
		}
	}
	cout<<ans;
	return 0;
}
/*不会了只能骗分
www就过了前四个样例 
求CCF给点分啊,40也好! 
*/ 
