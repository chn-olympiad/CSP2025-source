#include<bits/stdc++.h>
using namespace std;
string a;
long long b[100001],l=0,n,k;	
void A1(){
	sort(b+1,b+n+1);
	cout<<b[n];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	
	if(k<=1) A1();
}
