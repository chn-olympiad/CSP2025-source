#include<bits/stdc++.h>
using namespace std;
long long min3(long long a,long long b,long long c){
	if(a<=b&&a<=c)return a;
	if(b<=a&&b<=c)return b;
	return c;
}
long long min5(long long a,long long b,long long c,long long d,long long e){
	while(!(a<=b&&b<=c&&c<=d&&d<=e)){
		if(a>b)swap(a,b);
		if(b>c)swap(b,c);
		if(c>d)swap(c,d);
		if(d>e)swap(d,e);
	}
	return a+b;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,a,b,c,d,e,cnt=0;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		cnt+=min3(a,b,c);
	}
	for(int i=0;i<k;i++){
		cin>>a>>b>>c>>d>>e;
		cnt+=min5(a,b,c,d,e);
	}
	cout<<cnt;
	return 0;
}
	
