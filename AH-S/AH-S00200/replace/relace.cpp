#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("relac.in","r",stdin);
	freopen("relac.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string s1,s2;
		cin>>s1>>s2;
	}
	for(int i=0;i<q;i++){
		int s=0;
		string t1,t2;
		int v1[26],v2[26];
		cin>>t1>>t2;
		for(int j=0;j<t1.size();j++)
			v1[t1[j]-'a']++;
		for(int j=0;j<t2.size();j++)
			v2[t2[j]-'a']++;
		for(int i=0;i<26;i++){
			if(v1[i]>=1&&v2[i]>=1)
				s++;
		}
		cout<<s<<endl;
	}
	return 0;
}
//6666666666666666666666666666666666666666666666666666666666
