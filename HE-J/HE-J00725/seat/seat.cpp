#include <bits/stdc++.h>
//#Shang4Shan3Ruo6Shui4
using namespace std;
int x[1000],a[110][110];

bool cmp(int a,int b){
	if(a>b) return true;
	else return false;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>x[i];
	}
	y=x[1];
	if(n==1&&m==1) 
	{
		cout<<"1 1";
		return 0;
	}
	sort(x+1,x+n*m+1,cmp);
	int h=1,l=1;
	for(int i=1;i<=n*m;i++)
	{
		if(h>n && l%2!=0)
		{
			h=n;
			l++;
			a[h][l]=x[i];
			continue;
		}
		else if(h==1&&l%2==0)
		{
			l++;
			a[h][l]=x[i];
		}
		if(l%2==0)
		{
			h--;
			a[h][l]=x[i];
		}
		else{
			a[h][l]=x[i];
			h++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==y)
			{
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
 
	return 0;
} 
