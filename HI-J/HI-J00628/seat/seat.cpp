#include <bits/stdc++.h>
using namespace std;
int s[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,n,m;
	cin>>a>>b;
	n=a*b;
	if(a*b<=1){
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	m=s[0];
	sort(s,s+1);
	if(a==1){
	for(int i=0;i<n;i++){
		if(s[i]==m){
			cout<<a<<" "<<b-i;
		}
	}
}
    if(b==1){
    for(int i=0;i<n;i++){
		if(s[i]==m){
			cout<<a-i<<" "<<b;
		}
	}
}
	return 0;
}
