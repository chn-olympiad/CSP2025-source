#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long s[100000];
long long r[100000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<=n*m-1;i++) cin>>s[i];
	long long k=s[0];
	sort(s,s+n*m);
	for(long long i=n*m-1;i>=0;i--){
		r[i]=s[n*m-1-i];
		if(r[i]==k){
			k=i+1;
		}
	} 
	cout<<(k-1)/n+1<<" ";
	if(((k-1)/n+1)%2==1){
		if(k%n==0) cout<<n;
		else cout<<k%n;
	}else{
		if(k%n==0) cout<<1;
		else cout<<n-(k%n)+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

