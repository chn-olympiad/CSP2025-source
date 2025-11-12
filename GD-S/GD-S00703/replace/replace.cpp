#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,ans,cnt;
map<string,string>m;
map<string,bool>f;
map<string,int>ha;
int gu[N];
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		int begin=0,end=a.size()-1;
		while(a[begin]==b[begin])begin++;
		while(a[end]==b[end])end--;
		a=a.substr(begin,end);
		b=b.substr(begin,end);
		m[a]=b;
		f[a]=true;
		if(!ha[a]){
			ha[a]=cnt;
			cnt++;
		}
		gu[ha[a]]++;
	}
	for(int i=1;i<=q;i++){
		string s1,s2,s3="\0",s4="\0";
		cin>>s1>>s2;
		ans=0;
		bool fp=false;
		for(int p=1;p<=n;p++){
			if(s1[p]!=s2[p]){
				if(fp){
					ans=-1;
					break;
				}
				while(s1[p]!=s2[p]){
					s3=s3+s1[p];
					s4=s4+s2[p];
					p++;
				}fp=true;
				if(f[s3]&&m[s3]==s4){
					ans+=gu[ha[s3]]++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
