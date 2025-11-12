#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int tu[25];
struct QP
{
	int l,r;
};
QP qp[1000005];
int qptop = 1;
int d_s(int x)
{
	int z = 0,i = 0;
	while(x>0)
	{
		//cout<<z<<" "<<x<<" "<<x%10<<" "<<tu[i]<<endl;
		z+=(x%10)*tu[i];
		x/=10;
		i++;
	}
	return z;
}
int s_d(int x)
{
	int z = 0,i = 23;
	while(x>0||i>=0)
	{
		//cout<<z<<" "<<x<<" "<<tu[i]<<endl;
		z*=10;
		if(x-tu[i]>=0)
		{
			x-=tu[i];
			z++;
		}
		i--;
	}
	return z;
}
int xoor(int x,int y)
{
	int z,i = 1;
	x = s_d(x);
	y = s_d(y);
	if(x>=y)
	{
		while(x>0)
		{
			if(x%10 != y%10) z+=i;
			x/=10;
			y/=10;
			i*=10;
		}
		return z;
	}
	else
	{
		while(y>0)
		{
			if(x%10 != y%10) z+=i;
			x/=10;
			y/=10;
			i*=10;
		}
		return z;
	}
	return 0;
	
}
void find(int l,int r)
{
	if(l == r)
	{
		if(a[l] == k)
		{
			qp[qptop].l = l;
			qp[qptop].r = r;
			qptop++;
			//cout<<l<<" "<<r<<endl;
			return ;
		}
	}
	int sum = a[l];
	for(int i = l+1;i<=r;i++)
	{
		//cout<<"sum:"<<sum<<" a[i]:"<<a[i]<<" xor(sum,a[i]):"<<d_s(xoor(sum,a[i]))<<endl<<"tu.sum:"<<s_d(sum)<<" tu.a[i]:"<<s_d(a[i])<<" tu.xor(sum,a[i]):"<<xoor(sum,a[i])<<endl;
		sum = d_s(xoor(sum,a[i]));
	} 
	//cout<< endl;
	if(sum == k) 
	{
		qp[qptop].l = l;
		qp[qptop].r = r;
		//cout<<l<<" "<<r<<endl;
		qptop++;
		return ;
	}
	return ;
	
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	tu[0] = 1;
	for(int i = 1;i<=23;i++)
	{
		tu[i] = tu[i-1]*2;
	}
	cin >> n>> k;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = i;j<=n;j++)
		{
			find(i,j);
			//cout<< endl;
		}
	}
	cout<< qptop;
	return 0;
}
