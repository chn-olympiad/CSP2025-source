#include<bits/stdc++.h>
#define int long long
#define MAXN 200005
using namespace std;
string A[MAXN],B[MAXN],w1,w2;
int N,Q,ans;
int check(string s1,string t,string t1,string s2){
	int ans = 0;
	for(int i = 0 ; i < (int)s1.size();i ++){
		if(s1[i] == t[0]){
			bool is = true;
			for(int j = 1; j < (int)t.size();j ++ )
				if(s1[i + j] != t[j]){
					is = false;
					break;
				}
			if(is){
				string tmp = s1;
				for(int j = 0;j < (int)t.size();j ++)
					tmp[i + j] = t1[j];
				if(s2 == tmp)ans++;
			}
		}
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>N>>Q;
	for(int i = 1;i <= N;i ++)
		cin>>A[i]>>B[i];
	for(int i = 1;i <= Q;i ++){
		cin>>w1>>w2;
		int ans = 0;
		for(int i = 1; i <= N; i ++){
			ans += check(w1,A[i],B[i],w2);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
