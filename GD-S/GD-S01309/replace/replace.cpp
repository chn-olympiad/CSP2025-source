#include <bits/stdc++.h>
using namespace std;
int n,q,hs[1145],an;
string s1[1145],s2[1145],t1,t2,tt,tr;
bool ycheck(int x){
	for(int i=x;i<t1.length();i++){
		if(t1[i]!=t2[i]) return false;
	}
	return true;
}
bool rcheck(int x,int y){
	for(int i=0;i<s1[y].length();i++){
		if(s1[y][i]!=t1[x+i]||s2[y][i]!=t2[x+i]) return false;
	}
	return true;
}
void check(int x){
	for(int i=0;i<=t1.length()-s1[x].length();i++){
		if(rcheck(i,x)) if(ycheck(i+s1[x].length())) an++;
		if(t1[i]!=t2[i]) return;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int it=1;it<=q;it++){
		an=0;
		cin>>t1>>t2;
		if(t1.length()!=t2.length()){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			check(i);
		}
		cout<<an<<"\n";
	}
	return 0;
}
