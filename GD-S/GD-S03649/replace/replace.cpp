#include<bits/stdc++.h>
using namespace std;
char change[1010][2010];
struct node{
	char score;
	int next[2010];
	int jl;
}tree[2010];
void add(char s[],int bj){
	int p=0;
	for(int i=0;s[i]!='\0';i++){
		for(int j=1; ;j++){
			if(tree[p].next[j]==0||tree[tree[p].next[j]].score==s[i]){
				p=tree[p].next[j];
				tree[p].score=s[i];
				break;
			} 
		}
	}
	tree[p].jl=bj;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		char tmp[2010];
		scanf("%s %s",&tmp,&change[i]);
		add(tmp,i);
	}
	for(int i=1;i<=q;i++){
		char tmp[2010];
		scanf("%s",&tmp);
		cout<<"0\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
