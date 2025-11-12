#include<bits/stdc++.h>
using namespace std;
string s1[200002];
string s2[200002];
string t1;
string t2;
int n,q;
int an;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >>n>>q;
	for(int i=1;i<=n;i++){
		cin >>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		an=0;
		cin >>t1>>t2;
		int d=t1.size();
		string s11;
		string s22;
		for(int j=0;j<d;j++){
			if(t1[j]!=t2[j]){
				s11+=t1[j];
				s22+=t2[j];
			}
		}
		for(int j=1;j<=n;j++){
			if(s1[j]==t1&&s2[j]==t2)
				an++;
			if(s1[j]==s11&&s2[j]==s22){
				an++;
			}
		}
		cout <<an<<endl;
	}
	return 0;
}
