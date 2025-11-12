#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N];
int find(string s,string st){
	for(int i=0;i+st.size()-1<s.size();i++){
		bool flag=true;
		for(int j=0;j<st.size();j++)
			if(st[j]!=s[i+j]) flag=false;
		if(flag) return i;
	}return s.size();
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}string st1="",st2="";
		int p1=0,p2=0,ans=0;
		for(int i=0;i<t1.size();i++)
			if(t1[i]!=t2[i]){
				p1=i;
				break;
			}
		for(int i=t1.size()-1;i>=0;i--)
			if(t1[i]!=t2[i]){
				p2=i;
				break;
			}
		for(int i=p1;i<=p2;i++){
			st1=st1+t1[i];
			st2=st2+t2[i];
		}
		for(int i=1;i<=n;i++){
			int pos1=find(t1,s1[i]);
			int pos2=find(t2,s2[i]);
			int pos3=find(s1[i],st1);
			int pos4=find(s2[i],st2);
			if(pos1==pos2&&pos1!=t1.size()&&pos3==pos4&&pos3!=s1[i].size())
				ans++;
		}cout<<ans<<endl; 
	}
	return 0;
}
