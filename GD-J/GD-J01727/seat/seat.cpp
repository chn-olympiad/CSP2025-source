#include <bits/stdc++.h>
using namespace std;
long long a[105];
bool cmp (long long a,long long b){
	return a>b;
}
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	long long n,m,f=0;
	cin >> n >> m;
	for (long long i=1;i<=n*m;i++){
		cin >> a[i];
	}
	f=a[1];
	sort(a+1,a+1+n*m,cmp);
	for (long long i=1;i<=n;i++){
		for (long long j=1;j<=m;j++){
			if (j%2==0){
				if (a[(j-1)*n+n-i+1]==f){
					cout << j << " " << i;
					break;
				}
			}else{
				if (a[(j-1)*n+i]==f){
					cout << j << " " << i;
					break;
				}
			}
			
		}
	}
	return 0;
}

