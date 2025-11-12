#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[105],k;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int t=1;t<=n*m;t++){
		if(a[t]==k){
			int i=(t+n-1)/n,j=0;
			if(i%2==1){
				if(t%n==0) j=n;
				else j=t%n;
			}
			else{
				if((n-t%n+1)%n==0) j=n;
				else j=(n-t%n+1)%n;
			}
			cout<<i<<" "<<j;
			return 0;
		}
	}
	return 0;
}