#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,l[N],r;
string s1[N],s2[N],t1,t2;
bool v;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++){
		cin>>s1[i]>>s2[i];l[i]=s1[i].size();
	}
	while(q--){
		cin>>t1>>t2;
		for(int i=0; i<t1.size(); i++){
			for(int j=1; j<=n; j++){
				if(t1.substr(i,l[j])==s1[j]){
					string e=t1;
					for(int k=0; k<l[j]; k++)e[i+k]=s2[j][k];
					if(e==t2)r++;
				}
			}			
		}
		cout<<r<<"\n";
	}
	return 0;
}
