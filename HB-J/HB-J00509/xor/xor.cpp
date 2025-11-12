#include<bits/stdc++.h>
using namespace std;
int n,s,a[500009];
bool p=true;
string rjz(int x){
	string t;
	while(x){
		t=char(x%2+'0')+t;
		x/=2;
	}
	return t;
}
string awh(string q,string w){
	string sb;
	while(q.size()!=w.size()){
		if(q.size()<w.size())q='0'+q;
		else w='0'+w;
	}
	int l=q.size();
	for(int i=0;i<l;i++){
		if(q[i]==1&&w[i]==1)sb+='0';
		else sb+='1';
	}
	return sb;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>s;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)p=false;
	}
	if(p){
		if(s==0){
			if(n%2==0)cout<<n;
			else cout<<n-1;
		}
		else{
			if(n%2!=0)cout<<n;
			else cout<<n-1;
		}
		return 0;
	}
	int maxs=-1;
	for(int i=n;i>=0;i--){
		for(int j=0;j<n-i+1;j++){
			string q,w,sb;
			q=rjz(a[j]);
			for(int k=j+1;k<j+i-1;k++){
				w=rjz(a[k]);
				sb=awh(q,w);
				q=sb;
			}
			if(q==rjz(s)){
				maxs=max(maxs,i);
			}
		}
	}
	cout<<maxs;
	
	
	return 0;
}
