#include<bits/stdc++.h>
using namespace std;
const int N=5e6;
int n,q;
vector<pair<string,string> >v[N+1];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,s1;
		cin>>s>>s1;
		int l=s.length();
		v[l].push_back(make_pair(s,s1));
	}
	for(;q>0;q--){
		int cnt=0;
		string s1,s2;
		cin>>s1>>s2;
		int l,r;
		bool f1=false;
		int l1=s1.length();
		for(int i=0;i<l1;i++){
			if(s1[i]!=s2[i]){
				if(!f1){
					l=i;
					f1=true;
				}
				else{
					r=i;
				}
			}
		}
//		cout<<l<<' '<<r<<endl;
		for(int i=0;i<=l;i++){
			for(int j=l1-1;j>=r;j--){
				int len=j-i+1;
				for(int k=0;k<v[len].size();k++){
					bool f=1;
					string t1=v[len][k].first;
					string t2=v[len][k].second;
					for(int u=i,u1=0;u<=j;u++,u1++){
						if(t1[u1]!=s1[u]||t2[u1]!=s2[u]){
//							cout<<i<<' '<<j<<endl;
							f=0;
							break;
						}
					}
					if(f)cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
}
/*
4 2
xabcx xadex
ab cd 
bc de
aa bb
xabcx xadex
aaaa bbbb
*/ 
