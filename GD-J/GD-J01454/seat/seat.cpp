#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[20][20],r,index;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1)
			for(int j=1;j<=n;j++)
				b[i][j]=a[++index];
		else 
			for(int j=n;j>=1;j--)
				b[i][j]=a[++index];
	}for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(b[i][j]==r)cout<<i<<" "<<j;	
			return 0;
}

