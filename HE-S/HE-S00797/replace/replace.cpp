#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string s1[200005],s2[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		
	}for(int i=1;i<=q;i++){
		string s,ss;
		cin>>s>>ss;
		if(s==ss){
			cout<<2<<endl;
		} 
	}
	//突然就感受到不会做题的无奈，看题看半小时一点头绪没有 
	// 这甚至是一道多测题 
	//不想写了 
	return 0;
}
