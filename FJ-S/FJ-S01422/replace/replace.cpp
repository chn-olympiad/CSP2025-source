#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
struct f{
	string s1,s2;
}s[200005];
int vs[5000005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	string c1,c2;
	for(int i=1;i<=q;i++){
		cin>>c1>>c2;
		bool q=0;
		int st,e,ans=0;
		for(int j=0;j<c1.size();j++){
			if(c1[j]!=c2[j]){
//				cout<<c1[i]<<" "<<c2[i]<<endl;
				if(q==0){
					st=j;
					q=1;
				}
				e=j;
			}
		}
		string x="",y="";
		for(int j=st;j<=e;j++){
			x+=c1[j],y+=c2[j];
		}
		for(int j=st;j>=0;j--){
			for(int k=e;k<c1.size();k++){
				string qqq=x,qqw=y;
				for(int p=st-1;p>=j;p--){
					qqq=c1[p]+qqq;qqw=c2[p]+qqw;
				}
				for(int p=e+1;p<c1.size();p++){
					qqq=qqq+c1[p];qqw=qqw+c2[p];
				}
				for(int p=1;p<=n;p++){
					if(qqq==s[p].s1 && qqw==s[p].s2){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
}

