#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q;
string s1[N],s2[N],t1,t2;
int lens[N],posb1[N],posb2[N],dif[N];
int a[27][27];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int len=s1[i].size();
		for(int j=0;j<len;j++){
			if(s1[i][j]=='b') posb1[i]=j;
			if(s2[i][j]=='b') posb2[i]=j;
		}
		dif[i]=posb2[i]-posb1[i];
	}
	while(q--){
		cin>>t1>>t2;
		int b1,b2,d,ans=0;
		int len=t1.size();
		for(int i=0;i<len;i++){
			if(t1[i]=='b') b1=i;
			if(t2[i]=='b') b2=i;
		}
		d=b2-b1;
		for(int i=1;i<=n;i++){
			if(d==dif[i]&&posb1[i]<=b1&&s1[i].size()-posb1[i]<=len-b1) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
