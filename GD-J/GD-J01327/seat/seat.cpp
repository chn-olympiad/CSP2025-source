#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[(i-1)*m+j]==t){
				if(i&1){
					cout<<i<<" "<<j<<"\n";
				}else cout<<i<<" "<<m-j+1<<"\n";
				return 0;
			}
		}
	}
	return 0;
} 
