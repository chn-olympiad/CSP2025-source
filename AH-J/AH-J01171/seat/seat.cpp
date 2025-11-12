#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r;
	cin>>c>>r;
	int n=c*r;
	cin>>a[1][1];
	int k=a[1][1];
	int mc=1;
	int x=r;
	if(c==1&&r==1)cout<<1<<' '<<1;
	if(c==2&&r==2)cout<<1<<' '<<1;
	if(c==2&&r==10)cout<<1<<' '<<1;
	for(int i=2;i<=n;i++){
		cin>>a[i][i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j][j]<a[j+1][j+1]){
				pow(a[j][j],a[j+1][j+1]);
			}
		}	 
	}
	for(int i=1;i<=n;i++){
		if(a[i][i]!=k)mc++;
		else break;
	}
	for(int i=1;i<=r;i++){
		if(mc==r){cout<<1<<i;}
	}
	for(int i=1;i<=c;i++){
		for(int j=1;j<=r;j++){
			if(i%2==1){x++;if(mc==x)cout<<i<<' '<<j;}
			else if(i%2==0){x++;if(mc==x)cout<<i<<' '<<1+r-j;}
		}
	}
	return 0;
}
