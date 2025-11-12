#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,k,s=0;
	cin>>n>>m;
	cin>>t;
	for(int i=2;i<=n*m;i++){
		cin>>k;
		if(t<k){
			++s;
		}
	}
	if(s/n%2==0){
		cout<<s/n+1<<' '<<s%n+1;
	}
	else{
		cout<<s/n+1<<' '<<n-(s%n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
