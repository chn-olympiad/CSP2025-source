//GZ-S00210 贵阳市第一中学 朱九萌 
#include<bits/stdc++.h>
#define NN 200005
#define int long long
using namespace std;
int n,q;
string t1,t2;
struct aaa{
	string s1,s2;
}str[NN];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str[i].s1>>str[i].s2;
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int len1=t1.length();
		int len2=t2.length();
		if(len1!=len2){
			cout<<0<<"\n";
			continue;
		}
		int cnt=0;
		for(int j=1;j<=n;j++){
			int f=t1.find(str[j].s1);
			if(f==-1){
				continue;
			}
			string begin1="";
			for(int k=0;k<f;k++){
				begin1+=t1[k];
			}
			int len3=str[j].s1.length();
			string end1="";
			for(int k=f+len3;k<=len1-1;k++){
				end1+=t1[k];
			}
			if(begin1+str[j].s2+end1==t2){
				cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
