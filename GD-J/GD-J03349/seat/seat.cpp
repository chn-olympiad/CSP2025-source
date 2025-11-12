#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a1,an,b=0;
	cin>>a1;
	for(int i=2;i<=n*m;i++)
	{
		cin>>an;
		if(an>a1)b++;
	}
	b++;
	int x=b/n;
	if(b>x*n)x++;
	int y;
	if(x%2==1){
		y=b-((x-1)*n);
	}else{
		y=n-(b-((x-1)*n))+1;
	}
	cout<<x<<" "<<y;
	return 0;
} 
