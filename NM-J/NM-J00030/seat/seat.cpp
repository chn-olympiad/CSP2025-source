#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int cmp(int a,int b){
	return a>b;
}
const int N=1e7+10;
int a[N],n,m,ming;
int main() {

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll cnt=1;
	cin>>n>>m;
	int b[n][m],a[n*m+11];
	ll fuckk=n*m;
	for(int i=1; i<=fuckk; i++) {
		cin>>a[i];
	}
	if(n==1&&m==1) {
		cout<<'1';
		return 0;
	}
	ming=a[1];
	sort(a,a+fuckk,cmp);
	int i=1,j=1,nmb=0,tmd=0;
	while(fuckk--){
		b[i][j]==a[cnt];
		if(a[cnt]==ming) cout<<i<<' '<<j;
		cnt++;
		if(j==n&&nmb!=i) {
			i++;
			nmb=i;
		}
		else if(j==1&&tmd!=i&&i+j!=2){
			i++;
			tmd==i;
			
		}
	    else if(i%2==1) j++;
		else if(i%2!=1) j--;
		
	}
	return 0;
}
