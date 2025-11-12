#include<bits/stdc++.h>
using namespace std;
int n,q;
long long ans;
string s1[200010],s2[200010],t1,t2;
bool check(string t1,string t2,string s1,string s2,int st){
	if (st+s1.size()>t2.size())return false;
	for (int i=0;i<s1.size();i++){
		if (t1[i+st]!=s1[i])return false;
		t1[i+st]=s2[i];
	}
	for (int i=0;i<t1.size();i++){
		if (t1[i]!=t2[i])return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for (int i=1;i<=q;i++){
		cin>>t1>>t2;
		ans=0;
		for (int j=0;j<t1.size();j++){
			for (int k=1;k<=n;k++){
				if (check(t1,t2,s1[k],s2[k],j)){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

