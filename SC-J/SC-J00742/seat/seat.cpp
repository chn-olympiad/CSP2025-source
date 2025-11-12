#include<bits/stdc++.h>
using namespace std;
int a[110];
int b[12][12];
bool cmp(int a,int b){
	if(a>b)return true;
	else return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int t=a[0];
	int s=0;
	sort(a,a+n*m,cmp);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[i][j]=a[s];s++;
			if(b[i][j]==t)cout<<i<<" "<<j;
		}
	}
	return 0;
}