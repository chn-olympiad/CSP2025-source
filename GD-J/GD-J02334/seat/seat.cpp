#include<bits/stdc++.h>
using namespace std;
int n,m,s[120],b=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
		if(i>1&&s[i]>s[1])b++;
	}
	cout<<ceil(b*1.0000/n)<<" ";
	if((int)ceil(b*1.0000/n)%2){
		if(b%n==0)cout<<n;
		else cout<<b%n;
	}else{
		if(b%n==0)cout<<1;
		else cout<<n-b%n+1;
	}
} 
