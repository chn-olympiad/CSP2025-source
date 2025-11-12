#include<bits/stdc++.h>
using namespace std;
int n,m,sum,a[114],f,s[11][11],t;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			t++;
			if(a[t]==sum){
				if(i%2){
					cout<<i<<' '<<j;
					return 0;
				}cout<<i<<' '<<n+1-j;
				return 0;
			}
		}
	}return 0;
}
