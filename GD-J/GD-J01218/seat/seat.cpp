#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n*m-1;i++){
		cin>>b;
		if(a<b)ans++;
	}
	int q=(ans%n)+1,w=(ans/n)+1;
	cout<<w<<" ";
	if(w%2==1)cout<<q;
	else cout<<n-q+1;
	return 0;
} 
