#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	if(a>b){
		return a>b;
	}
	return 0;
}
long long n,m,a[100][100],n1,m1,o,b[10000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>b[o];
		o++;
	}
	int u=b[0];
	sort(b,b+o,cmp);
	o=0;
	for(long long j=1;j<=m;j++){
		for(long long i=1;i<=n;i++){
			if(b[o]==u){
				if(j%2==1){
					cout<<j<<" "<<i;
					return 0;
				}
				else{
					cout<<j<<" "<<n-i+1;
					return 0;
				}
			}
			o++;
		}
	}
 } 