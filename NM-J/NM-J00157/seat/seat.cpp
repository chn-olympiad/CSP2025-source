#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int a[100005];
int bmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int ws=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int xx=a[1];
	sort(a+1,a+1+n*m,bmp);
	for(int i=1;;i++)
		 if(xx==a[i]){ws=i;break;}
	if(ws<=n){x=1;y=ws;cout<<x<<" "<<y;return 0;}
	if(ws==n*m){  if(m%2==0){cout<<"1"<<" "<<m;return 0;}
					else {cout<<n<<" "<<m;return 0;}
				}
	int x=ws/n+1;
	if(x%2!=0) y=ws%n;
		else y=n-ws%n+1;
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
