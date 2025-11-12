#include <bits/stdc++.h>
using namespace std;
bool choose(int p;int q;int n){
	if(p>q>n||p>n>q)
		return p;
	else if(q>p>n||q>n>p)
		return q;
	else
		return n;
	}
int main(){
///freopen("club.in","r","stdin");
///freopen("club.out","w","stdout");
	int t,n,sum=0;
	cin>>t>>n;
	for(int i=0;i<=n;i++){
		if(t<=n/2)
		sum+=choose(i);
	}
	cout<<sum<<endl;	
}				

