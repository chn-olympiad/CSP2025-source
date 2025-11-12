#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+100;
int n,q;
map<pair<string,string>,bool>mp;

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[{s1,s2}]=1; 
	}
//	if(q==1){
//		int ans=0;
//		string t1,t2;
//		cin>>t1>>t2;
//		int n=t1.size(),m=t2.size();
//		int i=0,j=1;
//		while(i<=min(n,m)-1&&t1[i]==t2[i])i++;
//		while(j<=min(n,m)&&t1[n-j]==t2[m-j])j++;
//		for(int k=i;k+j<=n;k++){
//			cb1+=t1[k];
//		}
//		for(int k=i;k+j<=m;k++){
//			cb2+=t2[k];
//		}
//		
//		cout<<ans<<'\n';
//	}
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int n=t1.size(),m=t2.size();
		int i=0,j=1;
		while(i<=min(n,m)-1&&t1[i]==t2[i])i++;
		while(j<=min(n,m)&&t1[n-j]==t2[m-j])j++;
		for(int k=0;k<=i;k++){
			string s1,s2;
			for(int l=k;l<=n-j;l++)s1+=t1[l];
			for(int l=k;l<=m-j;l++)s2+=t2[l];
			for(int l=0;l<=j;l++){
				if(l!=0)s1+=t1[n-j+l],s2+=t2[m-j+l];
//				cout<<s1<<"  "<<s2<<"\n";
				if(mp[{s1,s2}])ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
