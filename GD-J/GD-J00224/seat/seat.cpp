#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N=110;
ll m,n,a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	ll b=a[1],c=m*n;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=c-n*(i-1)-3;j>=c-i*n;j--){
				if(b==a[j]){
					cout << i << " " << c-j+1;
					break;
				}
			}
		}else{
			for(int j=c-i*n;j<=c-n*(i-1)+1;j++){
				if(b==a[j]){
					cout << i << " " << c-j;
					break;
				}
			}
		}
		
	}
	
	return 0;
}
