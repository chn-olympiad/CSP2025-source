#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		int cnt=0;
		cin>>t1>>t2;
		for(int j=1;j<=n;j++){
			if(t1.find(s1[j])<t1.size()&&t1.find(s1[j])>=0){
				int p=0;
				string tmp=t1;
				for(int k=t1.find(s1[j]);k<t1.find(s1[j])+s1[j].size();k++){
					tmp[k]=s1[j][p];
					p++;
				}
				if(tmp==t2) cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}