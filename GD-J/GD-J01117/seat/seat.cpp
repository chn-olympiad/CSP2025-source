#include<bits/stdc++.h>
const int N=1005;
struct ff{
	int cj;
	int h,l,id;
}a[N];
using namespace std;
bool cmp(ff x,ff y){
	return x.cj>y.cj;
}
int n,m,x=1,y=1,p,q;
bool z=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	q=n*m;
	for(int i=1;i<=q;i++){
	cin>>a[i].cj;
	a[i].id=i;
	}
	sort(a+1,a+q+1,cmp);
	for(int i=1;i<=q;i++)if(a[i].id==1)p=i;
	for(int i=1;i<=q;i++){
		a[i].h=x;
		a[i].l=y;
		if(y<m&&z==1)
			y++;
		else if(y==m&&z==1){
			x++;
			z=0;
		}
		else if(y<=m&&y!=1&&z==0)
			y--;
		else if(y==1&&z==0){
			x++;
			z=1;
		}
	}
	cout<<a[p].h<<" "<<a[p].l;
	return 0;
}//·ê¿¼±Ø¹ý 
