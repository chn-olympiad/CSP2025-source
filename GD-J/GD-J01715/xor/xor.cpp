#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],maxcnt=0;
vector<int>b;
vector<int>c;
void XOR(){
	if(b.size()==0)return;
	for(auto x:b){
		if(x==k){
			maxcnt++;
		}
		else c.push_back(x);
	}
	b.clear();
	for(int i=1;i<c.size();i++){
		b.push_back(c[i]^c[i-1]);
	}
	c.clear();
	XOR();
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1){
			b.push_back(a[i]^a[i-1]);
		}
	}
	XOR();
	cout<<maxcnt<<endl;
	return 0;
}

