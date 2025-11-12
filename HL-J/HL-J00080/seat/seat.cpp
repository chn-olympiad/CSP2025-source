#include<bits/stdc++.h>
using namespace std;
const int N=100;
long long n,m,idx;
bool f=1;
long long a[10000],b[100][100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	long long r=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=m;i++){
		if(f==1){
			for(int j=1;j<=n;j++){
				b[j][i]=a[++idx];
				if(b[j][i]==r){
					cout << i << " " << j;
					return 0;
				}
				f=0;
			}
		}else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[++idx];
				if(b[j][i]==r){
					cout << i << " " << j;
					return 0;
				}
				f=1;
			}
		}
	}
    return 0;
}
