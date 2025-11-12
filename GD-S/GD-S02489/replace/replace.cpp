#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,q,a[MAXN],l[MAXN],r[MAXN],cnt;
string s1[MAXN],s2[MAXN];
unordered_map<string,int>mp;
unordered_map<string,bool>vis;
void solve1(){
	for(int i=1;i<=n;i++)mp[s1[i]]=i;
	while(q--){
		vis.clear();
		string t1,t2;
		cin>>t1>>t2;
		cnt=0;
		string l="";
		for(int i=0;i<t1.size();i++){
			string temp="";
			for(int j=i;j<t1.size();j++){
				temp+=t1[j];
				int k=mp[temp];
				if(k>0){
					string w=l+s2[k]+t1.substr(j+1,t1.size()-1);
					if(w==t2)cnt++;
				}
			}
			l=l+t1[i];
		}
		cout<<cnt<<"\n";
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	if(n*n*q<=1e7){
		solve1();
		return 0;
	}
	for(int i=1;i<=n;i++){
		int x1,x2;
		bool flag=0;
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b'){
				flag=1;
				x1=j;
				continue;
			}
			if(flag==0)l[i]++;
			else r[i]++;
		}
		for(int j=0;j<s2[i].size();j++){
			if(s2[i][j]=='b'){
				x2=j;
				break;
			}
		}
		a[i]=x2-x1;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		cnt=0;
		int x1,x2,left=0,right=0;
		bool flag=0;
		for(int i=0;i<t1.size();i++){
			if(t1[i]=='b'){
				x1=i;
				flag=1;
				continue;
			}
			if(flag==0)left++;
			else right++;
		}
		for(int i=0;i<t2.size();i++){
			if(t2[i]=='b'){
				x2=i;
				break;
			}
		}
		int k=x2-x1;
		for(int i=1;i<=n;i++)if(left>=l[i]&&right>=r[i]&&k==a[i])cnt++;
		cout<<cnt<<"\n";
	}
	return 0;
}
