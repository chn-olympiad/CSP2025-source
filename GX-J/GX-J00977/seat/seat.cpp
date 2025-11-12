#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s[101];
	cin>>n>>m;
	int c;
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	c=s[0];
	for(long long i=0;i<n*m;i++){
		for(long long i=0;i<n*m-1;i++){
		if(s[i]<s[i+1]){
			int b=s[i];
			s[i]=s[i+1];
			s[i+1]=b;
			}
	}}
		for(long long i=0;i<n*m;i++){
		if(s[i]==c){
			cout<<i/n+1<<' ';
			if((i/n+1)%2==0){
			cout<<n-(i%n);
		}
		else{
			cout<<(i%n)+1;
		}
			}
	}
	return 0;
}
