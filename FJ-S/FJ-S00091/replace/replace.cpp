#include<iostream>
#include<map>
using namespace std;
const int MAXN=2e5+5;
int n,q;
string s[MAXN][5];
map<string,string> mp;
bool check(string x,string y,int a,int b){
	string t1="",t2="";
	for(int i=a;i<=b;i++){
		t1+=x[i];
		t2+=y[i];
	}
	return mp[t1]==t2;
}
bool check1(string x,string y,int a){
	string t1="",t2="";
	for(int i=a;i<x.size();i++){
		if(x[i]!=y[i]) return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		mp[s[i][1]]=s[i][2];
	}
	for(int i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;
		int m=x.size(),cnt=0;
		for(int j=0;j<m;j++){
			for(int k=j;k<m;k++){
				if(j!=0&&x[j-1]!=y[j-1]){
					break;
				}
				if(k!=n-1&&!check1(x,y,k+1)){
					continue;
				}
				if(check(x,y,j,k)) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
