#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =1145;
int a[N],b[20][20];
int m,n,r;

bool cmp(int x,int y)
{
	return x>y;
}
int solve (int m,int j)
{
	int res,t=0;
	for(int i = m;i>=1;i--)
	{
		t++;
		if(j==i)res = t;
	}
		
	return res;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i<=n*m;i++)
	{
		cin>>a[i];
	}
	r = a[1];
	sort(a+1,a+n*m+1,cmp);
	int t = 0;
	for(int i = 1; i <= n;i++)
		for(int j = 1;j <= m;j++)
		{
			t++;
			b[i][j] = a[t];
			if(b[i][j] == r){
				if(i%2==0)
				{
					cout << i <<" "<<solve(m,j);
					break;
				}
				else
				{
					cout <<i <<" "<<j;
					break;
				}
			}
		}
	
	
	return 0;
}
