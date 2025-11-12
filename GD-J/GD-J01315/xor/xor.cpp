#include<bits/stdc++.h>
using namespace std;
long long a,s,f=0,g,h[5001],j,k,l=1;
//char c[10000000];
bool cmp(long long a,long long b){
	return a>b;
}
long long m(long long a,long long b){
	return (a|b)-(a&b);
}
void q(long long y,long long x){
	if(y>g){
		l=g+1;
		return;
	}
	long long p=0;
	for(long long o=x;o<=y;o++){
		p=m(p,h[o]);
	}
	if(p==j){
		l=y+1;
		k++;
		//cout<<x<<' '<<y<<endl;
	}else{
		q(y+1,x);
	}
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>g>>j;
	for(long long p=1;p<=g;p++){
		cin>>h[p];
	}
	for(;l<=g;){
		q(l,l);
	}
	cout<<k;
	return 0;
}
