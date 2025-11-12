#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
void get_seat(int n,int m,int pos,int &x,int &y)
{
	a[1][1]=1;
	x=1,y=1;
	for(int p=2;p<=pos;p++)
	{
		if((y&1)?(x==n):(x==1))
			y++;
		else if(y&1)x++;
		else x--;
	}
}
//01ers笑传之 0dt
//feropen
//freopen("seat.in","r",stdout);
//freopen("seat.out","w",stdin);
//NeVer G0nna GiVe Y0u uP 
//I planted up a segment tree

//dfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdf
//狂笑的蛇将写散文 
int b[1010];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
		if(b[i]>=b[1])cnt++;
	}
	int x,y;
	get_seat(n,m,cnt,x,y);
	cout<<y<<' '<<x<<'\n';
	return 0;
}

//与普遍的看法相反，opia 并不是一首关于眼病的歌 
//By Luogu 1076971
//----  | --  |
//| | | -- | | +
//---- | |  | --
//先生，以上并不是我对 df 的全部赞誉。 
