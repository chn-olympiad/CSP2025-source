#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100100],l,i,j,n,m,x;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) x=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	i=1,j=1;
	while(1){
		l++;
		if(a[l]==x){
			cout<<j<<" "<<i;
			return 0; 
		}
		if(j%2==0){
			if(i==1)j++;
			else i--;
		}
		else if(j%2==1){
			if(i==n) j++;
			else i++;
		}
		
	}
	return 0;
} 
