#include<bits/stdc++.h>
using namespace std;
long long he,n;
long long a[5010];
bool cmp(const long long &x,const long long &y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(n<3){
		he=0;
	}else if(n==3){
		long long d=0;
		for(long long i=1;i<=n;i++){
			d+=a[i];
		}
		if(d>2*a[1]){
			he=1;
		}else{
			he=0;
		}
	}else{
		he=0;
	}
	cout<<he;
return 0;
}
