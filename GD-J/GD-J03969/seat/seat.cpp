#include<iostream>
#include<algorithm>
using namespace std;
int n,m,cnt,c,r;
struct node{
	int num;
	int book;
}a[110];
bool cmp(node a,node b){
	return a.num>b.num;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
			cin>>a[i].num,a[i].book=0;
	a[1].book=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) 
		if(a[i].book==1){
			cnt=i;break;
		} 
	int o=(cnt-1)/n;
	r=o+1;
	if(o%2==0)
		c=cnt-o*n;
	else
		c=r*n-cnt+1;
	cout<<r<<" "<<c;
	return 0;
} 
