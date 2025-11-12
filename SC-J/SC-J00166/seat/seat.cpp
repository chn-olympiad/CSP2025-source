#include<bits/stdc++.h>
using namespace std;
int a[110];int b[110][110];
int c[110][110];
bool cmp(int a1,int a2){
	if(a1>=a2){
		return true;
	}else{
		return false;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n;int m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int d=a[1];
	sort(a+1,a+n*m+1,cmp);
	int p1=1;
	int p2=1;
	for(int i=1;i<=n*m;i++){
		if(p2%2==1){
			b[p1][p2]=a[i];
			p1++;
			if(p1==n+1){
				p1=1;
				p2++;
			}			
		}else{
			b[n-p1+1][p2]=a[i];
			p1++;
			if(p1==n+1){
				p1=1;
				p2++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==d){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
} 