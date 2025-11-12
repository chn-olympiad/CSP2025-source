#include<bits/stdc++.h>
using namespace std;
int n,t;
string s[200005];
string ss[200005];
string qs[200005];
string qss[200005];
int l[200005];
int r[200005];
map<string,string> q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>ss[i];
		q[s[i]]="";
	}
	for(int i=1;i<=t;i++){
		cin>>qs[i]>>qss[i];
		l[i]=qs[i].size();
		for(int j=0;j<qs[i].size();j++){
			if (qs[i][j]!=qss[i][j]){
				l[i]=j;break;
			}
		}
		r[i]=0;
		for(int j=qs[i].size()-1;j>=0;j--){
			if (qs[i][j]!=qss[i][j]){
				r[i]=j;break;
			}
		}
//		cout<<"           "<<l[i]<<' '<<r[i]<<endl;
		for(int j=0;j<=l[i];j++){
			for(int k=r[i]-l[i]+1;k<qs[i].size()-l[i]+1;k++){
				q[(qs[i].substr(j,k))]="";
			}
		}
	}
	for(int i=1;i<=n;i++){
		q[s[i]]=ss[i];
	}
	int ans;
	for(int i=1;i<=t;i++){
		ans=0;
//		cout<<"           "<<l[i]<<' '<<r[i]<<endl;
		for(int j=0;j<=l[i];j++){
			for(int k=r[i]-j+1;k<qs[i].size()-j+1;k++){
				if (q[(qs[i].substr(j,k))]==(qss[i].substr(j,k))){
					ans++;
				}
//				cout<<"     "<<(qs[i].substr(j,k))<<' '<<q[(qs[i].substr(j,k))]<<' '<<(qss[i].substr(j,k))<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
