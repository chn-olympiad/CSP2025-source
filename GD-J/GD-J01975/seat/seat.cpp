#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int ji=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++cnt];
			if(cnt==1) ji=a[cnt];
		}
	}
	sort(a+1,a+n*m+1),reverse(a+1,a+n*m+1);
	int pl=0;
	for(int i=1;i<=n*m;i++){
		if(ji==a[i]){pl=i;break;}
	}
	int s=0,x=1,y=1;
	while(s<pl)
	{
		s++;
		if(s==pl) break; 
		if(x==n&&y%2==1) y++;
		else if(x==1&&y%2==0) y++;
		else if(y%2==1) x++;
		else if(y%2==0) x--;
	}
	return cout<<y<<" "<<x,0;
}
