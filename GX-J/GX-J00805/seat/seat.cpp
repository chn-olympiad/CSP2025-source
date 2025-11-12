#include<bits/stdc++.h>
using namespace std;
long long s[1001][1001];
long long a[10000001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,c=1,r=1,sum,o=100;
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[1]==s[c][r]){
			cout<<c<<" "<<r;
		}
		if(c<m){
			for(int j=0;j<m;j++){
				s[c][r]=o;
				c+=1;
				if(r>n)	r-=1;
				if(r<1)	r+=1;
				o--;
			}
		}if(c>m){
			for(int j=0;j<m;j++){
				s[c][r]=o;
				c-=1;
				if(r>n)	r-=1;
				if(r<1)	r+=1;
				o--;
			}
		}
		
	}
	return 0;
}
