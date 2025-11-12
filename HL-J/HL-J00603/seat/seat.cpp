#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,mc=1,c,r;
	cin>>n>>m;
	int x=n*m,room[n][m],ch[x];
	for(int i=0; i<x; i++)
		cin>>ch[i];
	if(n==m && n=='1')
	{
		cout<<"1"<<" "<<"1";
	}
	for(int i=0; i<x; i++)
	{
			if(ch[0]<ch[i])
				mc++;
	}
	if((mc%n)!=0)
		c=((mc-(mc%n))/n)+1;
	else
		c=((mc-(mc%n))/n);

	if(c/2==1)
		r=mc%n;
	else
		r=m-1*c;

	cout<<c<<" "<<r;
	return 0;
}