#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],k,r;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++k];
		}
	}
	r=a[1];
	sort(a+1,a+k+1,cmp);
	k=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(r==a[++k]){
				if(i%2==1){
					cout<<i<<" "<<j;
					return 0;
				}else{
					cout<<i<<" "<<n-j+1;
					return 0;
				}
			}
		}
	}
	return 0;
}
