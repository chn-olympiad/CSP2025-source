#include<bits/stdc++.h>
using namespace std;
long long a[10005];
long long cmp(long long n,long long m){
	return n>m;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long rs=n*m;
    for(long long i=1;i<=rs;i++){
    	cin>>a[i];
	}long long aa=a[1],mc;
    sort(a+1,a+1+rs,cmp);
   	for(long long i=1;i<=rs;i++){
	    if(a[i]==aa){
	    	mc=i;
	    	break;
		}
	}long long c,r;
    if(mc%n==0){
    	c=mc/n;
	}else{
		c=mc/n+1;
	}if(c%2==1){
		r=mc-((c-1)*n);
	}else if(c%2==0){
		r=n-(mc-((c-1)*n))+1;
	}cout <<c<<" "<<r;
	return 0;
}
