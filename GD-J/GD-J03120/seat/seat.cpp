#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001],s[1001][1001],x=1,y=1,k,ans;
void abc(int xx,int yy,int kk){
	if(kk==1){
		if(xx+1>n)
			y++;
		else
			x++;
	}
	else{
		if(xx-1<1)
			y++;
		else
			x--;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	ans=a[1];
	sort(a+1,a+1+n*m);	
	for(int i=n*m;i>=1;i--){
		s[x][y]=a[i];
		if(s[x][y]==ans)
			break;
		k=y%2;
		abc(x,y,k);
	}
	cout<<y<<" "<<x<<"\n";
	return 0;
}
