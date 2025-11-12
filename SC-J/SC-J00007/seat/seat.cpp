#include<bits/stdc++.h>
using namespace std;
int num[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>num[(j-1)*n+i];
	ans=num[1];
	sort(num+1,num+n*m+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(num[(j-1)*n+i]==ans){
				cout<<i<<" ";
				if(i%2==0)
					cout<<m-j+1;
				else cout<<j;
				cout<<endl;
			}
	return 0;
}