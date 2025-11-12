#include<bits/stdc++.h>
using namespace std;
struct repstring{
	string fr,ma,mb,bk;
}Rep[200001];
repstring Trans(string s1,string s2){
	repstring T;
	T.fr=T.ma=T.mb=T.bk="";
	int nowf=0;
	for(int j=0;j<s1.size();j++){
		if(s1[j]==s2[j]){
			if(nowf)T.bk+=s1[j];
			else T.fr+=s1[j];
		}
		else{
			nowf=1;
			T.ma+=T.bk;
			T.mb+=T.bk;
			T.bk="";
			T.ma+=s1[j],T.mb+=s2[j];
		}
	}
	return T;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		Rep[i]=Trans(s1,s2);
	}
	for(int i=1;i<=q;i++){
		long long ans=0;
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		repstring now=Trans(t1,t2);
		for(int j=1;j<=n;j++){
			repstring tocomp=Rep[j];
			if(now.ma!=tocomp.ma||now.mb!=tocomp.mb)continue;
			if(now.fr.size()<tocomp.fr.size())continue;
			if(now.bk.size()<tocomp.bk.size())continue;
			int dfr=now.fr.size()-tocomp.fr.size(),dbk=now.bk.size()-tocomp.bk.size();
			int flag=1;
			for(int i=0;i<tocomp.fr.size();i++){
				if(tocomp.fr[i]!=now.fr[i+dfr]){
					flag=0;
					break;
				}
			}
			for(int i=0;i<tocomp.bk.size();i++){
				if(tocomp.bk[i]!=now.bk[i]){
					flag=0;
					break;
				}
			}
			ans+=flag;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
