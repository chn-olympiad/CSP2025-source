#include<bits/stdc++.h>
using namespace std;
long long a[1100000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long flag=a[1];
	sort(a,a+1+n*m);
	long long h,l;
	for(long long j=1;j<=n*m;j++){
		if(a[j]==flag){
			long long i=n*m+1-j;
			if(i%n==0){
				l=i/n;
			}else{
				l=i/n+1;
			}
			if(l%2==1){
				h=i%n;
				if(h==0){
					h=n;
				}
			}else{
				if(i%n==0){
					h=1;
				}else{
					h=n+1-(i%n);
				}
			}
		}
	}
	cout<<l<<" "<<h;
    return 0;
}
//#Shang4Shan3Ruo6Shui4
