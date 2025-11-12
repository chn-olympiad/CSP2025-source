#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
typedef struct Node{
	string str1;
	string str2;
	int len;
}Node;
Node node1[200005];
Node node2[200005];
int l,r;
void solve1();
void bfs(int l,int r,int cnt);
bool cmp(const Node n1,const Node n2){
	return n1.len<n2.len;
}
bool check(string s1,string s2);
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=q;i++){
		cin>>node1[i].str1>>node1[i].str2;
		node1[i].len=node1[i].str1.size();
	}
	for (int i=1;i<=n;i++){
		cin>>node2[i].str1>>node2[i].str2;
		node2[i].len=node2[i].str1.size();
		
	}
	sort(node2+1,node2+1+n,cmp);
	solve1();
	return 0;
}
void bfs(int l,int r,int cnt){
	string nstr1="",nstr2="";
	for (int i=l;i<=r;i++){
		nstr1+=node1[cnt].str1[i];
	}
	for (int i=l;i<=r;i++){
		nstr2+=node1[cnt].str2[i];
	}
	int nlen=nstr1.size();
	if (nlen>node2[n].len)return ;
	if (l>0)bfs(l-1,r,cnt);
	if (r<node2[n].len-1)bfs(l,r+1,cnt);
	
	
	for (int i=1;i<=n;i++){
		if (node2[i].len!=nlen)continue;
		if (check(node2[i].str1,nstr1)&&check(node2[i].str2,nstr2))ans++;
	}
	return ;
}
bool check(string s1,string s2){
	int len1=s1.size();
	for (int i=0;i<len1;i++){
		if (s1[i]!=s2[i])return false;
	}
	return true;
}
void solve1(){
	for (int k=1;k<=q;k++){
		l=0,r=node1[k].len-1,ans=0;
		string d1;
		string d2;
		d1=node1[k].str1;
		d2=node1[k].str2;
		int all=d2.size();
		for (int i=0;i<all;i++){
			if (d1[i]!=d2[i]){
				l=i;
				break;
			}
		}
		
		for (int i=l;i<all;i++){
			if (d1[i]==d2[i]){
				r=i-1;
				break;
			}
		}
		bfs(l,r,k);
		cout<<ans<<endl;
	}
	
	return ;
}
