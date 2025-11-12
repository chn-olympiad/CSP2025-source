#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
string s;
int a[505];
long long pa(long long n){
	long long p=1;
	for(int i=n;i>=1;i--){
		p=p*i%998244353;
	}
	return p;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int cnt=0;
	bool yet=false;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'&&yet==false){
			cnt++;
		}
		else{
		yet=true;
	}
	}
	if(cnt>=m){
		printf("%lld",pa(n));
	}
	else{
	printf("0");
}
	return 0;
}
