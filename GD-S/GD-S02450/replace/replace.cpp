#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=' ';
	int sum=0;
	while(!(ch>='0'&&ch<='9'))ch=getchar();
	while(ch>='0'&&ch<='9'){
		sum=(sum<<3)+(sum<<1)+ch-'0';
		ch=getchar();
	}
	return sum;
}
int T,n;
string s1[200005],s2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	T=read();
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
	}
	while(T--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			int res=t1.find(s1[i]);
			if(res!=-1){
				string t=t1;
				t.erase(res,s1[i].size());
				t.insert(res,s2[i]);
				if(t==t2)++ans;
			}
		}
		printf("%d\n",ans);
	}
} 
/*
Too difficult.
Think 1.5hours,but got no ideas.
I think I was foo__sh.What can I do now?
Maybe 30pts.

Uid:753204 mywzj_mo
bits\stdc++.h
//freopen
freeopen
freopen("replace.out","r",stdin)
freopen("replace.in","w",stdout)
int mian(){
cnt_broken=4;

Frisk! Keep your determination!

His theme.(but not mine)
Hopes and dreams.(but now I am hopeless)
Save the world.(But I unaable to do anything but think)
Snowing towns.(Yes.But now I am cold and blue.)

Oh.Your determination is broken.

My friend:XDB(Baned User),PuShuai(Not oier).
------They ask me to write them into the code.

*/

