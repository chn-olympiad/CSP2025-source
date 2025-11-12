#include <bits/stdc++.h>
using namespace std;
long long n,m,a[10010]={-1},l,k;
bool cmp(long long x,long long y){
		return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];	
	}
	l=a[1];
	long long len=n*m;
	sort(a+1,a+len+1,cmp);
	int i=1,j=1;
	while(1){
		if(j%2==0&&i<1){
			j++;
			i=1;
		}else if(j%2==1&&i>n){
			j++;
			i=n;
		}
		if(j%2==0) k=n-i+1;
		else k=i;
		if(l==a[n*j-n+k]){
			cout<<j<<" "<<i<<endl;
			break;
		}
		if(j%2==0) i--;
		else i++;
	}
	return 0;
}
