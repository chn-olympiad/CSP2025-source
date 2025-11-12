#include<bits/stdc++.h>
using namespace std;
int s[100000050],l,n,m,sum,ans;
int r(int k,int j){
	for(int i=k;i<=j;i++){
		if (s[i]==l){
			return j-i+1;}
	}
	return -1;
}
int rw(int k,int j){
	for(int i=k;i>j;i--){
		if (s[i]==l){
			return k-i+1;}
	}
	return -1;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>l;
    s[1]=l;
    for(int i=2;i<=n*m;i++)cin>>s[i];
    sort(s+1,s+n*m+1);
    for(int i=m;i>0;i-=2){
		ans=rw(i*n,i*n-n);
		if(ans != -1){cout<<m-i+1<<' '<<ans;return 0;}
		sum=r((i-1)*n-n+1,(i-1)*n+1);
		if(sum != -1){cout<<m-i+2<<' '<<sum;return 0;}
	}	
	ans=r(n,1);
	if(ans != -1)cout<<m<<' '<<ans;
    return 0;
}
