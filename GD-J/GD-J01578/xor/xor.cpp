#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,ans,a[N],sum[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	/*
	Dddddddddddifficult!
	Try to get 10 point -ing
	I find there is a mistake(freopen => freoepn) in my code when I check my code,ое©чак.
	*/
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int c=0;
	for(int i=1;i<=n;i++){
		c^=a[i];
		if(a[i]==k || c==k){
			ans++;
			c=0;
		}
		
	}
	cout<<ans;
	return 0;
}
