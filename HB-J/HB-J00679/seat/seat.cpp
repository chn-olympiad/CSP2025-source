#include<bits/stdc++.h>
using namespace std;
int a[105];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	cin>>a[i];
	int num=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==num)
		{
			cout<<y<<' '<<x;
			break;
		}
		if(x==n&&y%2==1)	y++;
		else	if(x==1&&y%2==0)	y++;
		else	if(y%2==1)	x+=1;
		else	x-=1;
	}
	return 0;
}
