#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,q;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)cin>>s1[i]>>s2[i]; 
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		string pre="";
		int ans=0;
		for(int i=0;i<t1.size();++i){
			pre=pre+t1[i];
			for(int j=1;j<=n;++j){
				string mid="",nex="";
				if(s1[j].size()+i==t1.size())
					if(s1[j]==t1&&s2[j]==t2)++ans;
				if(s1[j].size()+i>t1.size())continue;
				for(int k=i+1;k<=i+s1[j].size();++k)mid=mid+t1[k];
				for(int k=i+s1[j].size()+1;k<t1.size();++k)nex=nex+t1[k];
				if(mid==s1[j]&&pre+s2[j]+nex==t2)++ans;
			}
		}
		printf("%d\n",ans);
	}
}
