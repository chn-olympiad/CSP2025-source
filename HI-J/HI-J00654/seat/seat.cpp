#include<bits/stdc++.h>
using namespace std;
long long s[1000000];
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int main(){
	long long n,m,o,p,l=0;
	cin>>n>>m;
	for (long long i=1;i<=n*m;i++){
		if (i==1){
			cin>>o;
		}
		cin>>s[i];
		l++;
	}
	sort(s,s+l);
	for (long long i=1;i<=n*m;i++){
		if (s[i]==o){
			p=i;
		}
	}
	cout<<p/n+1<<"  ";
	if((p/n+1)%2==0){
		cout<<n-p%n; 
	}
	else{
		cout<<p%n+1;
	}
	return 0;
}
