#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
int n,q;
string s1[N],s2[N],t1,t2;
void solve1(){
	cin>>t1>>t2;
	if(t1.size()!=t2.size()){
		printf("0\n");
		return;
	}
	int m=t1.size(),l=-1,r=-1,ans=0;
	for(int i=1;i<=n;i++){
		int l=t1.find(s1[i]);
		if(l==-1)continue;
		string t3=t1;
		for(int j=l;j<l+s1[i].size();j++){
			t3[j]=s2[i][j-l];
		}
		if(t3==t2)ans++;
	}
	printf("%d\n",ans);
}
void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--)solve1();
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	solve();
	return 0;
}
