#include<bits/stdc++.h>
using namespace std;
long long a,s,f=0,g,h[5001],j,k,l;
//char c[10000000];
bool cmp(long long a,long long b){
	return a>b;
}
void q(long long x,long long y,long long z,long long t,bool i){
	if(x>g+1){
		return;
	}
	if(y>z*2&&t>=3&&i==0){
		k++;
		k%=998244353;
	}
		//cout<<x<<' '<<y<<' '<<t<<endl;
	q(x+1,y+h[x],max(h[x],z),t+1,0);
	q(x+1,y,z,t,1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>g;
	for(long long p=1;p<=g;p++){
		cin>>h[p];
	}
	q(1,0,0,0,0);
	cout<<k;
	return 0;
}
