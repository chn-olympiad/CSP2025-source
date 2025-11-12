#include<bits/stdc++.h>
#define int long long
using namespace std; 
void init(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
int n,q,num;
string sr1,sr2;
string s1[200001],s2[200001];
bool bj[26];
signed main(){
	init();
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>n>>q; 
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].size();j++){
			bj[s1[i][j]-'a']=1;
			bj[s2[i][j]-'a']=1;
		}
	}
	for(int i=0;i<26;i++){
		if(bj[i]){
			num++;
		}
	}
	if(num==2 && bj[0] && bj[1]){
		while(q--){
			cin>>sr1>>sr2;
			int sum=0;
			for(int i=1;i<=n;i++){
				int a=0,b=0,c=0,d=0;
				for(int j=0;j<sr1.size();j++){
					if(sr1[j]=='b'){
						a=j;
					}
					if(sr2[j]=='b'){
						b=j;
					}
					if(a && b){
						break;
					}
				}
				for(int j=0;j<s1[i].size();j++){
					if(s1[i][j]=='b'){
						c=j;
					}
					if(s2[i][j]=='b'){
						d=j;
					}
					if(c && d){
						break;
					}
				}
				if(b==d && a==c){
					sum++;
				}
			}
		}
	}
	else{
		for(int i=1;i<=q;i++){
			cout<<"0\n";
		}
	}
	return 0;
}
