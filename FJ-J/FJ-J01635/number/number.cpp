#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(string x,string y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n = s.size();
	for(int i=0;i<n;i++){
		if(s[i]=="a" && s[i]=="z"){
			s.erase(i,i);
		}
	}
	sort(s,s+n,cmp);
	cout<<s;
	
	
	
	return 0;
}
