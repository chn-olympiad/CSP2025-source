#include<bits/stdc++.h>
using namespace std;
#define int LL
typedef long long LL;
const int mod=998244353;
int n,q;
string s1[200010],s2[200010];
int d[400010];
map<pair<int,int>>mp;
string t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		d[200001+s1[i].find(b)-s2[i].find(b)]++;
	}
	if((n<=1005&&q<=1005)||q==1){
		while(q--){
			int ant=0;
			cin>>t1>>t2;
			if(t1.size()!=t2.size()){
				cout<<"0\n";
				continue;
			}
			for(int i=1;i<=n;i++){
				if(t1.find(s1[i])!=-1){
					string ss1=t1.substr(0,t1.find(s1[i])),ss2=t1.substr(t1.find(s1[i])+s1[i].size(),t1.size()-t1.find(s1[i])-s1[i].size());
					if(ss1+s2[i]+ss2==t2){
						ant++;
					}
				}
			}
			cout<<ant<<"\n";
		}
	}else{	
		while(q--){
			cin>>t1>>t2;
			if(t1.size()!=t2.size()){
				cout<<"0\n";
				continue;
			}
			int len=t1.find(b)-t2.find(b),fr=t1.find(b),en=t1.size()-t1.find(b)-1;
			/*
			
			*/
			cout<<d[200001+len];
		}
	}
	return 0;
}