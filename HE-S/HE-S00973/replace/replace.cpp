#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	string s1,s2;
};
int n,q;
node s[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i].s1>>s[i].s2;
	while(q--){
		node qu;
		int cnt=0;
		cin>>qu.s1>>qu.s2;
		for(int i=1;i<=n;i++){
			int len=s[i].s1.size();
			for(int j=0;j+len<=qu.s1.size();j++){
				if(qu.s1.substr(j,len) == s[i].s1){
					string cc;
					for(int k=0;k<j;k++) cc+=qu.s1[k];
					cc+=s[i].s2;
					for(int k=j+len+1;k<qu.s1.size();k++) cc+=qu.s1[k];
					if(cc == qu.s2) cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
