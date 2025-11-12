#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200000][2],t[200000][2];
struct str{
	string s1,s2;
};
str err={"-1","-1"};
str haves(string s,string t){
	if(s.size()>t.size())return err;
	for(int i=0;i<=t.size()-s.size();i++){
		bool flag=1;
		for(int j=0;j<s.size();j++){
			if(s[j]!=t[i+j]){
				flag=0;
				break;
			}
		}if(flag){
			string y21="",y22="";
			for(int j=0;j<i;j++){
				y21+=t[j];
			}for(int j=i+s.size();j<t.size();j++){
				y22+=t[j];
			}return {y21,y22};
		}
	}return err;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=0;i<q;i++){
		cin>>t[i][0]>>t[i][1];
	}
	for(int i=0;i<q;i++){
		int ans=0;
		string t1=t[i][0],t2=t[i][1];
		int cnt1=0,cnt2=t1.size()-1;
		string x="",y1="",y2="",z="";
		while(t1[cnt1]==t2[cnt1]&&cnt1<=t1.size()-1)cnt1++;
		while(t1[cnt2]==t2[cnt2]&&cnt2>=cnt1)cnt2--;
		for(int j=0;j<cnt1;j++){
			x+=t1[j];
		}for(int j=cnt1;j<=cnt2;j++){
			y1+=t1[j];
			y2+=t2[j];
		}for(int j=cnt2+1;j<t1.size();j++){
			z+=t1[j];
		}for(int j=0;j<n;j++){
			str l1=haves(y1,s[j][0]);
			if(err.s1==l1.s1&&err.s2==l1.s2)continue;
			str l2=haves(y2,s[j][1]);
			if(l2.s1!=l1.s1||l2.s2!=l1.s2)continue;
			str left=haves(l1.s1,x),right=haves(l1.s2,z);
			if(l1.s1=="")left.s2="";
			if(l1.s2=="")right.s1="";
			if(left.s2==""&&right.s1==""){
				ans++;
			}
		}printf("%d\n",ans);
	}
	return 0;
}
