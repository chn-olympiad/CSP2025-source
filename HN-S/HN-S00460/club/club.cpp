#include<bits/stdc++.h>
using namespace std;

int n,t,sum,k;
const int N = 100010;

int q(int a[],int v,int x,int cnt)
{
	sum = max(x,sum);
	//cout<<sum<<endl;
	if(cnt == n) return 0;
	if(v <= n/2) q(a,v + 1,x + a[cnt],cnt);
	q(a,v,x,cnt);
	cnt ++;
}

int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	cin>>n;
	for(int i = 0; i < t; i ++)
	{
		int a[N] = {0},b[N] = {0},c[N] = {0}; 
		for(int j = 1; j <= n; j ++) cin>>a[j]>>b[j]>>c[j];
		q(a,0,0,0);
		k += sum;
		sum = 0;
		q(b,0,0,0);
		k += sum;
		sum = 0;
		q(c,0,0,0);
		k += sum;
		sum = 0;
		cout<<k<<endl;
		k = 0;
	}
	
	return 0;
} 
