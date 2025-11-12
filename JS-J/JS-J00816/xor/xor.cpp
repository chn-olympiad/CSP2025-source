#include <bits/stdc++.h>
using namespace std;
queue <int>q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a,t=0,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		q.push(a);
	}
	a=0;
	while(!q.empty()){
		a=q.front();
		q.pop();
		t^=a;
		if(t==k){
			ans++;
			t=0;
		}
	}
	cout<<ans;
}
//^	  yi huo
