#include<bits/stdc++.h>
using namespace std;
int n,m,f[105],t,l=0;
bool  c(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n*m;i++){
		cin>>f[i];
	}
	t=f[0];
	sort(f,f+n*m,c);
	for (int i=0;i<n*m;i++){
		l++;
		if(f[i]==t) break;
	}
	if(l%n==0){
	    cout<<l/n<<" ";
		if((l/n)%2==0){
		    if(l%n==0) cout<<n;
		    else cout<<n-(l%n-1);
	    }
		else{
			if(l%n==0) cout<<n;
			else cout<<l%n;
		}
	}
	else {
	cout<<l/n+1<<" ";
		if((l/n+1)%2==0){
			if(l%n==0) cout<<n;
			else cout<<n-(l%n-1);
		}
		else{
			if(l%n==0) cout<<n;
			else cout<<l%n;
		}
    }
	return 0;
}
