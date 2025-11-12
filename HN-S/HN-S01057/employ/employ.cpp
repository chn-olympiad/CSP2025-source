#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],ans,v[505];string s;char s1[505];
vector<int> g;
void S(int x){
	if(x==n){
        int sum=0,i=1;
		for(auto it:g){
			if(s1[i]=='1' && sum<a[it]) sum++;
			i++;
		}
		if(sum>=m){
			ans++;	
			ans=ans%998244353;
		}
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			g.push_back(i);
			S(x+1);
			v[i]=0;
			g.pop_back();
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		s1[i+1]=s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	S(0);
	cout<<ans%998244353;
	return 0;
}
