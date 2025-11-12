#include<bits/stdc++.h>
using namespace std;
long long n,m,c,r,a[101],f,p,s;//c lie;r hang
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	f=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
	    p+=1;
        if(a[i]==f) break;
	}
	s=p%(2*n);
	c+=(p/(2*n))*2;
	if(s==0){
        r=1;
	}else if(s<=n){
        r=s;
        c+=1;
	}else{
        r=2*n-s+1;
        c+=2;
	}
	printf("%lld %lld",c,r);
	return 0;
}
