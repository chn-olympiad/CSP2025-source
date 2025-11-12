#include<bits/stdc++.h>
using namespace std;
struct Node{
	int b;
	int son[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
}trie[5000005],trie1[5000005];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int tail=0,tail1=0;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		int now=0;
		for(int j=0;j<s.length();j++){
			int c=s[j]-'a';
			if(trie[now].son[c]==0){
				tail++;
				trie[now].son[c]=tail;
				now=tail;
			}
			else now=trie[now].son[c];
		}
		trie[now].b=i;
		string s1;
		cin>>s1;
		now=0;
		for(int j=0;j<s1.length();j++){
			int c=s1[j]-'a';
			if(trie1[now].son[c]==0){
				tail1++;
				trie1[now].son[c]=tail1;
				now=tail1;
			}
			else now=trie1[now].son[c];
		}
		trie1[now].b=i;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.length()!=s2.length()) printf("0\n");
		else{
			int ans=0,now=0,maxdiff=0,mindiff=100000000;
			for(int i=0;i<s1.length();i++){
				if(s1[i]!=s2[i]){
					mindiff=min(mindiff,i);
					maxdiff=max(maxdiff,i);
				}
			}
			while(now<=mindiff){
				int now1=0,now2=0;
				for(int i=now;(trie[now1].son[s1[i]-'a']!=0&&trie1[now2].son[s2[i]-'a']!=0&&i<s1.length());i++){
					now1=trie[now1].son[s1[i]-'a'];
					now2=trie1[now2].son[s2[i]-'a'];
					if(trie[now1].b>0&&(trie[now1].b==trie1[now2].b)&&i>=maxdiff) ans++;
				}
				now++;
			}
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
