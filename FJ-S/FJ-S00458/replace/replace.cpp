#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5+5,MAXQ=2e5+5;

int n,q;
// s1°¢s2£∫∆•≈‰ 
string s1[MAXN],s2[MAXN];

string sub(string& s,int l,int r){
	return s.substr(l,r-l+1);
}


// q1,q2£∫Œ Ã‚ 
int dfs(string q1,string q2){
	if (q1==q2) return 1;
	int ans=0;
	for (int i=1;i<=n;i++){
		//  s1[i]°¢s2[i]         q1°¢q2 
		int len1=s1[i].size(),len2=q1.size();
		
		for (int j=0;j<len2-len1+1;j++){
			if (q1.substr(j,len1)==s1[i]){
				string newstr=sub(q1,0,j-1)+s2[i]+sub(q1,j+len1,len2-1); 
				ans+=dfs(newstr,q2);
			}
		}
	}
	return ans;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	
	while (q--){
		string q1,q2;
		cin>>q1>>q2;
		cout<<dfs(q1,q2)<<endl;
	}
		
	return 0;
}
