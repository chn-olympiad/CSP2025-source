#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;bool f=1;int k=0;
int a[90][90],s[10009],x,y;
bool cmp(int a,int b){return a>b;} 
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int kk=n*m;
	for(int i=1;i<=kk;i++)cin>>s[i];
	int l=s[1];
	sort(s+1,s+1+kk,cmp);
	for(int j=1;j<=m;j++){
		if(f==1){
			for(int i=1;i<=n;i++)a[i][j]=s[++k];
			f^=1;
		}
		else {
			for(int i=n;i>=1;i--)a[i][j]=s[++k];
			f^=1;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]==l)x=j,y=i;
	cout<<x<<" "<<y;
	return 0;
}
