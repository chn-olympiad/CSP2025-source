#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000];
bool cmp(long long l,long long r){
	return l>r;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long qq;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	qq=a[1];
	long long js=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==qq){
			js=i;
			break;
		}
	}
	long long sb1,sb2;
	sb1=(js-1);
	sb1=sb1/n;
	sb1++;
	if(sb1%2==0){
		sb2=n-js%n+1;
	}else{
		sb2=js%n;
		if(js%n==0){
			sb2=n;
		}
	}
	printf("%lld %lld",sb1,sb2);
	
	return 0;
}
