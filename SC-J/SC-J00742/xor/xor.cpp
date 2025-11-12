#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
bool pana=1,panb=1;
	int n,k;cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=0||a[i]!=1)panb=0;
		if(a[i]!=1)pana=0;
	}
	if(pana&&k==0)cout<<n/2;
	return 0;
}