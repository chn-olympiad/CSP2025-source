#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m,n,i,j=1,k,a[110],r;
bool cmp(ll a,ll b){
	return a>b;
}
bool b,b2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m*n;i++){
		cin>>a[i];
	}
	r=a[1];
	i=0;
	sort(a+1,a+1+m*n,cmp);
	for(k=1;k<=n*m;k++){
		if(i==n&&b2==0){
			j++;
			b=1;
			b2=1;
		}else if(i==1&&j!=1&&b2==0){
			j++;
			b=0;
			b2=1;
		}else if(b==0){
			i++;
			b2=0;
		}else if(b==1){
			i--;
			b2=0;
		}
		if(a[k]==r){
			cout <<j<<" "<<i;
			return 0;
		}
	}
	return 0;
}
