#include<bits/stdc++.h>
#define F(i,x,y)for(int i=(x);i<=(y);i++)
using namespace std;
const int N=10000,S=100000;
int n,q,cnt,ok[N],h;
map<pair<int,int>,int> tr;

inline int calc (char x,char y){
	return (x-27)*26 +y-96;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	cnt=1;
	string s1,s2;
	F(i,1,n){
		cin>>s1>>s2;
		int now=1,sz=s1.size()-1;
		
	}
	if(s1.size()!=s2.size()){
			cout<<0<<endl;
	}
	return 0;
}