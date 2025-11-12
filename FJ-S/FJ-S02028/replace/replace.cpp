#include<bits/stdc++.h>
using namespace std;
map<pair<string,string>,int>v;
int n,q,l=1e9,r;
string sa[50005],sb[50005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>sa[i]>>sb[i],l=min(l,(int)sa[i].size()),r=max(r,(int)sb[i].size()),
		v[{sa[i],sb[i]}]=1;
	for(int i=1;i<=q;i++){
		int ans=0;
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size())cout<<"0\n";
		else{
			int m=a.size()-1,s=0,t=m;
			string ss="",xx="";
			for(;a[s]==b[s]&&s<=m;)s++;
			for(;a[t]==b[t]&&t>=0;)t--;
			if(s>t)s=t=(m+1)>>1;
			for(int j=s;j<=t;j++)ss+=a[j],xx+=b[j];
			if(v.find({ss,xx})!=v.end())ans++;
			string cc,dd;
			for(int j=s-1;j>=0;j--){
				ss=a[j]+ss,xx=b[j]+xx,cc=ss,dd=xx;
				for(int k=t+1;k<=m+1;k++){
					if(v.find({cc,dd})!=v.end())ans++;
					cc+=a[k],dd+=b[k];
				}
			}
			cout<<ans<<"\n";
		}
	}
}