#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,n1,m1;
	cin>>n>>m;
	int s[n*m+1],s1[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	k=s[1];
	sort(s+1,s+n*m+1);
	for(int i=1,u=n*m;i<=n*m;i++,u--){
		s1[u]=s[i];
	}
	for(int i=1;i<=n*m;i++){
		if(s1[i]==k){
			if(i%n!=0)n1=i%n;
			else n1=n;
			if(i%n!=0){
				m1=i/n+1;
			}
			else m1=i/n;
		}
	}
	cout<<m1<<" "<<n1;
	return 0;
}
