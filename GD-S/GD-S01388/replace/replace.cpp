#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int n,q;
struct node{
	string u,v;
};
vector<node> g;
int in(){
	int f=1,ans=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c==45)
			f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		ans=ans*10+c-48;
		c=getchar();
	}
	return f*ans;
}
//inline con(){
//	freopen("con","w",stdout);
//	FILE* t=popen("fc replace.out replace3.ans","r");
//	char c[128];
//	while(fgets(c,sizeof(c),t))
//		printf("%s",c);
//}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=in(),q=in();
	string s1,s2;
	for(int i=0;i<n;++i){
		cin>>s1>>s2;
		g.push_back({s1,s2});
	}
	int ans;
	bool fla;
	string s,ss;
	while(q--){
		cin>>s1>>s2;
		ans=0;
		for(node t:g){
			s="";
			if(t.u.size()>s1.size())
				continue;
			for(int i=0;i<s1.size()-t.u.size()+1;++i){
				fla=1;
				for(int j=0;j<t.u.size();++j){
					if(s1[i+j]!=t.u[j]){
						fla=0;
						break;
					}
				}
				if(fla){
					ss="";
					for(int j=i+t.u.size();j<s1.size();++j)
						ss+=s1[j];
					if(s+t.v+ss==s2)
						++ans;
				}
				s+=s1[i];
			}
		}
		printf("%d\n",ans);
	}
//	con();
	return 0;
}
