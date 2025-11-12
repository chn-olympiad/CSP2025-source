#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
struct Node{
	string s1,s2; 
}s[200001];
struct Node1{
	string sq1,sq2; 
}sq[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	for(int i=1;i<=n;i++){
		cin>>sq[i].sq1>>sq[i].sq2;
	}
	cout<<ans;
	return 0;
}
