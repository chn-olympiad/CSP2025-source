//GZ-00052 华东师范大学附属贵阳学校 刘宇宸 
#include <bits/stdc++.h>
using namespace std;
bool ini(string a,string b){
	bool u = false;
	for(int i = 0;i < b.size();i++){
		u = true;
		for(int j = i;j < a.size();j++){
			if(a[i] != b[i]){
				u = false;
			}
		}
		if(u){
			return u;
		}
	}
	return u;
}
int we(string a,string b){
	bool u = false;
	for(int i = 0;i < b.size();i++){
		u = true;
		for(int j = i;j < a.size();j++){
			if(a[i] != b[i]){
				u = false;
			}
		}
		if(!u){
			return i;
		}
	}
}
int n,q;
string t[5],s[200005][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		int y = 0;
		cin>>t[1]>>t[2];
		for(int i = 1;i <= n;i++){
			if(ini(s[i][2],t[2])){
				y++;
				s[i][2] = "";
			}
		}
		cout<<y<<endl;
	}
	
	
	return 0;
}
