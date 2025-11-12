#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
struct node{int x,y,num;}a[200];
bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=read(),m=read();
	for(int i=0;i<n*m;i++)a[i].num=read();
	int r=a[0].num;
	sort(a,a+n*m,cmp);
	int k=0;
	for(int i=1;i<=n;i++){
		if(i%2==1)for(int j=1;j<=m;j++,k++)a[k].x=i,a[k].y=j;
		else for(int j=m;j>=1;j--,k++)a[k].x=i,a[k].y=j;
	}
	for(int i=0;i<n*m;i++)if(a[i].num==r)cout<<a[i].x<<' '<<a[i].y;
	return 0;
} 
