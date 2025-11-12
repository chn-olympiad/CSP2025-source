#include<bits/stdc++.h>
using namespace std;
int t,n,a[i],q,j;
typedef long long ll;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	i=t-1,j=n;
	if(n=2){
	cin>>a[i];
	q=max(a[0][1],a[1][1])+max(a[0][2],a[1][2]);
	cout<<q;
	}
	return 0;
	
}
