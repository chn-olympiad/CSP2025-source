#include<bits/stdc++.h>
using namespace std;
const int N=150;
int n,m,a[N],r,x,ans,ansh;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=i;break;
		}
	}
	ans=(r-1)/n+1;
	if(ans%2==0){
		x=((r-1)/n)*n;
		ansh=n-(r-x)+1;
	}else{
		x=((r-1)/n)*n;
		ansh=r-x;
	}
	cout<<ans<<" "<<ansh;
	return 0;
}
