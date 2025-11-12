#include<bits/stdc++.h>
using namespace std;
const long long maxn=10010;
int b[maxn][maxn];
long long c[maxn],a[maxn];
int n,m1;
int m;
int k;
int q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m1;
	m=n*m1;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++){
		c[i]=a[m-i+1];
	}
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m1;j>=1;j--){
				q++;
				b[i][j]=c[q];
				if(c[q]==k){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else {for(int j=1;j<=m1;j++){
			q++;
			b[i][j]=c[q];
			if(c[q]==k){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		}
	}
		return 0;
}
