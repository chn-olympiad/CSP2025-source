#include <bits/stdc++.h>
using namespace std;
int t,sum;
struct f{ int l1,l2,l3,dx;}a[110000];
bool cmp1(f xx,f yy){
	return xx.dx>yy.dx;
}
bool ff[110000];
int x[110000],z[110000];
int rx=0;int ry=0;int rz=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while(t--){
		int n;rx=0;ry=0;rz=0;
		cin >>n;
		for (int i=1;i<=n;i++){
			cin >>a[i].l1>>a[i].l2>>a[i].l3;
			a[i].dx=max(a[i].l1-a[i].l2,a[i].l3-a[i].l2);
			ff[i]=true;
		}
		sort(a+1,a+n+1,cmp1);
		ry=n;
		for (int i=1;i<=n;i++){
			if (a[i].dx>0){
				ff[i]=false;
				if (a[i].l1>a[i].l3){
					ry--;
					rx++;
					x[rx]=i;
				}
				else{
					ry--;
					rz++;
					z[rz]=i;
				}
			}
		}
		
		for(int i=1;ry>n/2;i++){
			if (!ff[i])	continue;
			if (a[i].l1>a[i].l3){
				ry--;
				rx++;
				x[rx]=i;
			}
			else{
				ry--;
				rz++;
				z[rz]=i;
			}
		}
		for(int i=rx;rx>n/2;i--){
			if (a[i].l2>a[i].l3)
				rx--;
			else{
				rz++;
				rx--;
				z[rz]=x[rx+1];
			}
		}
		for(int i=rz;rz>n/2;i--)
			if (a[i].l2>a[i].l3)
				rz--;
		bool fff[n];sum=0;
		for (int i=1;i<=rx;i++){sum+=a[x[i]].l1;fff[x[i]]=true;}
		for (int i=1;i<=rz;i++){sum+=a[z[i]].l3;fff[z[i]]=true;} 
		for (int i=1;i<=n;i++)if (!fff[i])	sum+=a[i].l2;
		cout <<sum<<endl;
	}
	return 0;
}
