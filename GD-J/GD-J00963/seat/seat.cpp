#include<iostream>
using namespace std;
int a,b,bianhao,q,cj[405];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a*b;i++)cin>>cj[i];
	q=cj[1];
	for(int i=1;i<=a*b;i++)for(int j=i+1;j<=a*b;j++)if(cj[j]>cj[i])swap(cj[i],cj[j]);
	for(int i=1;i<=a*b;i++)if(q==cj[i])bianhao=i;
	int lie=(bianhao-1)/a+1;
	if(lie%2)cout<<(bianhao-1)%a+1<<" "<<lie;
	else cout<<a-(bianhao-1)%a<<" "<<lie;
	return 0;
}
