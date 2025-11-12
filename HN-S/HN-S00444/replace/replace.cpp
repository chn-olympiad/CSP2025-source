#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
string s1[200005],s2[200005];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string s,ss;
		cin>>s>>ss;
		if(s.size()!=ss.size()){
			cout<<0<<'\n';
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			int l1=s.size(),l2=ss.size(),len=s1[i].size();
			if(len>l1||len>l2) continue;
			int f1=s.find(s1[i]),f2=ss.find(s2[i]);
			if(f1==f2&&f1!=string::npos&&f2!=string::npos){
				string sa=s.substr(0,f1),ssa=s.substr(f1+len,l1-f1-len),sb=ss.substr(0,f1),ssb=ss.substr(f1+len,l1-f1-len); //sb->s×Ö·û´®µÄb 
				if((sa==sb)&&(ssa==ssb)){
					cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}

//     ***   *                               *
//     *     *                                
//   *****   *    *****   *****   *****      *   *****
//     *     *    *   *   *       *          *   *   *
//     *     *    *   *   *       *          *   *   *
//     *     **   *****   *       *      *   *   *****
