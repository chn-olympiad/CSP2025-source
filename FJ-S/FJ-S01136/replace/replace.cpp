#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,x[N],y[N];
string s[N][2];string q1,q2;
void solve(){	//+25pts
	int ans=0;
	int p=q1.find("b");
	int p2=q2.find("b");
	for(int i=1;i<=n;i++){
		if(x[i]<=p&&(y[i]-x[i])==(p2-p)&&q1.size()-p>=s[i][0].size()-x[i])ans++;
	}
	printf("%d\n",ans);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		x[i]=s[i][0].find("b"),y[i]=s[i][1].find("b");
	}
	for(int i=1;i<=q;i++){
		cin>>q1>>q2;
		solve();
	}
	return 0;
}

