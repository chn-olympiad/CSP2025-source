#include<bits/stdc++.h>
using namespace std;
int a[1005]={0,1,-1},n,m,x,b[100005],t,s=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	t=b[1];
	int l=n*m;
	sort(b+1,b+1+l);
	int i=1,j=1;
	while(i*j<=m*n){
		if(b[l]==t){
			cout<<j<<" "<<i;break;
		}
		if(i+1>n&&s==1){
			j++;s=2;
		}
		else if(i-1<1&&s==2){
			j++;s=1;
		}
		else i+=a[s];
		l--;
	}
	return 0;
}
