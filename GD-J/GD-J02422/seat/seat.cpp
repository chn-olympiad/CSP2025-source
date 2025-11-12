#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m;//n行，m列 
int tu[N];
int r;
int sum;
int ll,hh;
void wei(int num)
{
int lie;
int hang;
	if(num%n==0) lie=num/n;
	else lie=num/n+1;
	if(lie%2==1)
	{
		hang=num-(lie-1)*n;
	 } 
	 else{
	 	hang=n-(num-(lie-1)*n)+1;
	 }
	 ll=lie;
	 hh=hang;
}
bool mysort(int a,int b)
{
	return a>=b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	
	for(int i=0;i<n*m;i++)
	{
		cin>>tu[i];
	}
	r=tu[0];
	sort(tu,tu+n+m,mysort);
    for(int i=0;i<n*m;i++)
    {
    	if(tu[i]>r) sum++;//sum为比R分数高的人 
	}
sum++;
	if(sum==1)
	{
		cout<<"1"<<" "<<"1";
		return 0;
	}
wei(sum);
cout<<ll<<" "<<hh;
	return 0;
}
