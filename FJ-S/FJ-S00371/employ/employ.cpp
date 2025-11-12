#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long n,t;
	cin>>n>>t;
	long long b=1;
	long long a=1;
	for(int i=0;i<n;i++){
		
		a*=10;
	}
	for(int i=0;i<n;i++){
		
		b*=10;
	}
	cout<<a%b<<endl;
}
