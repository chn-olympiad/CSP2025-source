#include<bits/stdc++.h>
using namespace std;
int s[101],s_[101]; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)cin>>s[i];
	int R=s[1],a,b=0;
	sort(s+1,s+i);
	for(int i=m*n+1;i>=1;i--)s_[b++]=s[i];
	for(int i=1;i<=m*n;i++){
		if(s_[i]==R){
			a=i;
			break;
		}
	}
	for(int x=1;x<=m;x++){
		if(x==1)for(int y=1;y<=n;y++)if(y==a)cout<<x<<' '<<y;
		else if(x%2==0)for(int y=1;y<=n;y++)if((x*n-y+1)==a)cout<<x<<' '<<y;
		else if(x%2!=0)for(int y=1;y<=n;y++)if((x*n-n+y)==a)cout<<x<<' '<<y;
	}
	return 0;
}
