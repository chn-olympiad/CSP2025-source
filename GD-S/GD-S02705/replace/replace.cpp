#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int n,q,ans;
struct node{
	string a,b;
}
s[200005];
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		/*int st=0,ed=0;
		bool flag=0;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				if(flag==0){
					st=i;
					ed=i;
					flag=1;
				}else ed=i;
			}
		}
		string dt1="",dt2="";
		for(int i=st;i<=ed;i++){
			dt1=dt1+t1[i];
			dt2=dt2+t2[i];
		}*/
		for(int i=1;i<=n;i++){
			int id=t1.find(s[i].a),id2=t2.find(s[i].b);
			if(id!=-1&&id2!=-1&&id==id2){
				string zkm="";
				for(int i=0;i<id;i++) zkm=zkm+t1[i];
				zkm+=s[i].b;
				int tt=id+s[i].b.size();
				for(int i=tt;i<t1.size();i++) zkm+=t1[i];
				if(zkm==t2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
