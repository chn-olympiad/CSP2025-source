#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],s=0;
bool cmp(const long long x,const long long y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a[1];
    long long t=a[1],c=n*m;
    for(long long i=2;i<=c;i++) cin>>a[i];
    sort(a+1,a+c+1,cmp);
    for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				if(a[++s]==t){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[++s]==t){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}return 0;
}
