#include<bits/stdc++.h>
using namespace std;
long long n,q,ans,si1,si2;
string s1,s2,t1,t2;
map< string , string>m;
string strcut(string str,long long st,long long ed){
	string sum = "";
	for(int i = st;i <= ed;i++)
		sum += t1[i];
	return sum;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		cin>>s1>>s2;	
		m[s1] = s2;	
	}for(int i = 1;i <= q;i++){
		cin>>t1>>t2;
		si1 = t1.size();
		si2 = t2.size();
		ans = 0;
		for(int j = 0;j < si1;j++)
			for(int k = j + 1;k < si2;k++)
				if(strcut(t1,0,j - 1) + m[strcut(t1,j,k)] + strcut(t1,k + 1,si1 - 1) == t2)	
					ans++;
		cout<<ans<<endl;
	}
	return 0;
}
