#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
const ull salt=13131,N=1e5+5;
int n,q;
string t1[N],t2[N],l1,l2;
map<ull,string> to;
ull hashing(string s){
	int len=s.size();
	ull res=0;
	for(int i=0; i<len; i++)
		res+=(s[i]-'a')*salt;
}
int solve(){
	int len=l1.size(),ans=0;
	l1+=" ";
	for(int i=0; i<len; i++){
		for(int j=1; j<=n; j++)
		{
			if(l1.substr(i,t2[j].size())==t1[j]){
//				cout<<l1.substr(0,i)+t2[j]+l1.substr(t2[j].size()+i,99999)<<l2<<endl;
				if(l1.substr(0,i)+t2[j]+l1.substr(t2[j].size()+i,99999)==l2+" ") ans++;
			}
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++){
		cin>>t1[i]>>t2[i];
//		to[hashing(t1[i])]=t2[i];
	}
	for(int i=1; i<=q; i++){
		cin>>l1>>l2;
		cout<<solve()<<'\n';
	}
	return 0;
}


