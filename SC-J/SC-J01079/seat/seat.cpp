#include<bits/stdc++.h>
using namespace std;
int a[10005],mp[105][105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int a1;cin>>a1;
	a[1]=a1;
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+(n*m)+1);
	int x=1,y=1,k=n*m;
	int d=0;
	if(m%2==0)d=1;
	else d=n;
	//cout<<d<<" "<<m<<endl;
	while(y!=m||x!=d){
		if(a[k]==a1){
			cout<<y<<" "<<x;
			return 0;
		}
		mp[x][y]=a[k];
		k--;
		if((x==1&&y%2==0)||(x==n&&y%2==1)){
			y++;
			continue;
		}
		else if(y%2==0){
			x--;
			continue;
		}
		else{
			x++;
			continue;
		}
	}
	if(a[1]==a1)cout<<y<<" "<<x;
} 