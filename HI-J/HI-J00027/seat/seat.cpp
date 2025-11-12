#include<bits/stdc++.h>
using namespace std;
int smap(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110],b[15][15],c,d;
	bool flag=true;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+(m*n)+1,smap);
	c=1;d=1;
	for(int i=1;i<=m*n;i++)
	{
		b[c][d]=a[i];
		if(b[c][d]==r)
			break;
		if(c==n&&flag==true)
		{
			d++;
			flag=false;
			continue;
		}
		if(c==1&&flag==false)
		{
			d++;
			flag=true;
			continue;
		}
		if(flag==true)
			c++;
		else
			c--;
	}
	cout<<d<<" "<<c<<endl;
	fclose(stdin);fclose(stdout); 
	return 0;
}

