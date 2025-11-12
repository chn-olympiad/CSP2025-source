#include<bits/stdc++.h>
using namespace std;
int a[10010];
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[(i-1)*n+j]==r){
				int ans2=0;
				if(i%2==1){
					ans2=j;
				}
				else ans2=(n-j+1);
				cout<<i<<" "<<ans2;
				return 0;
			}
		}
		
	}
	return 0;
}
