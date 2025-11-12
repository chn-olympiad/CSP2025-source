#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n,k,l,r,d,w,s,u=1,a[500001];
void f(int x){
	while(l<r){
		d=l+r>>1;
		if(v[d]<x) l=d+1;
		else r=d;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k,v.push_back(0);
	for(int i=1;i<=n;i++){
		cin>>a[i],a[i]^=a[i-1],l=w,r=u,f(a[i]^k);
		if(r<u&&v[r]==(a[i]^k)) s++,w=u,u++,v.push_back(a[i]);
		else{
			l=w,r=u,f(a[i]);
			if(r==u||a[i]!=v[r]) u++,v.insert(v.begin()+r,a[i]);
		}
	}
	cout<<s;
	return 0;
}
