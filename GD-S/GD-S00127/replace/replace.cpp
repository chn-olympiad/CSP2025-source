#include<bits/stdc++.h>
using namespace std;
const int N=4e5+7;
int n,q,cnt;
string s[2];
struct {
	int son[26][26],ed,fail,dep;
}tr[N];
void insert(string s,string ss){
	int len=s.size(),now=0;
	for(int i=0;i<len;i++){
		int ch=s[i]-'a',chh=ss[i]-'a';
		if(!tr[now].son[ch][chh])
			tr[now].son[ch][chh]=++cnt,tr[cnt].dep=tr[now].dep+1;
		now=tr[now].son[ch][chh];
	}
	tr[now].ed++;
}
void get_fail(){
	queue<int>q;
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			if(tr[0].son[i][j])
				q.push(tr[0].son[i][j]);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			for(int j=0;j<26;j++){
				if(tr[now].son[i][j]){
					q.push(tr[now].son[i][j]);
					tr[tr[now].son[i][j]].fail=tr[tr[now].fail].son[i][j];
				}
				else tr[now].son[i][j]=tr[tr[now].fail].son[i][j];
			}
		}
	}
} 
void read(string &s){
	s.clear();
	char r=getchar();
	while(r<'a'||r>'z')r=getchar();
	while(r>='a'&&r<='z')s+=r,r=getchar();
}
int query(string s,string ss,int l,int r){
	int len=s.size(),now=0,res=0;
	for(int i=0;i<len;i++){
		int ch=s[i]-'a',chh=ss[i]-'a';
		now=tr[now].son[ch][chh];
		int tmp=now;
		while(tmp){
			if(i>=r&&i-tr[tmp].dep<l)res+=tr[tmp].ed;
			tmp=tr[tmp].fail;
		}
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		read(s[0]),read(s[1]);
		insert(s[0],s[1]);
	}
	get_fail();
	while(q--){
		read(s[0]),read(s[1]);
		int i=s[0].size()-1,j=0,len=s[0].size();
		while(i>=0&&s[0][i]==s[1][i])i--;
		while(j<len&&s[0][j]==s[1][j])j++;
		printf("%d\n",query(s[0],s[1],j,i));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 1
aa bb
abd bbd
aabdaa abbdaa
*/
