#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10,Q=5e6+10,L=5e6+10;
int n,q;
string s1,s2;
int same1=0,same2=n;
int ch[L][26],cnt[L],tot,ne[L];
string s2s[N];
bool check(int k,int j){
//	cout<<s2s[cnt[j]]<<endl<<s2<<endl;
	
	 
	string s=s2s[cnt[j]];
	int i=k-s.size()+1;
//	printf("%d %d\n%d %d\n",i,k,same1,same2);
	if(same1<i-1||same2>k+1) return 0;
	for(int j=0;j<s.size();j++){
		if(s[j]!=s2[i+j]) return 0;
	}
	
	return 1;
}

void insert(string s,int i){
	int p=0;
	for(int i=0;i<s.size();i++){
		int c=s[i]-'a';
		if(!ch[p][c]) ch[p][c]=++tot;
		p=ch[p][c];
	}
	cnt[p]=i;	
	return;
}
void build(){
	queue<int> q;
	for(int i=0;i<26;i++) if(ch[0][i]) q.push(ch[0][i]);
	while(q.size()){
		int u=q.front();q.pop();
		for(int i=0;i<26;i++){
			int v=ch[u][i];
			if(v) ne[v]=ch[ne[u]][i],q.push(v);
			else ch[u][i]=ch[ne[u]][i];
//			if(ne[v]) printf("u=%d v=%d ne[v]=%d ch[u][%c]=%d\n",u,v,ne[v],char(i+'a'),ch[u][i]);
		}
	}
	return;
}
ll query(string s){
	ll ans=0;
	
	for(int k=0,p=0;k<s.size();k++){
		int i=s[k]-'a';
		p=ch[p][i];
		for(int j=p;j;j=ne[j]){
//			printf("p=%d k=%d j=%d p->%d\n",p,k,j,cnt[j]);
			if(cnt[j]){
				ans+=check(k,j);
			}
		}
		
	}
	return ans;
}
void test(){
	for(int i=0;i<=tot;i++){
		for(int j=0;j<26;j++){
			if(ch[i][j]) printf("ch[%d][%c]=%d\n",i,char(j+'a'),ch[i][j]);
		}
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		string s1,s2;cin>>s1>>s2;
		insert(s1,i);
		s2s[i]=s2;
		
	}
	
	build();
//	test();
//	for(int i=0;i<=tot;i++) cout<<i<<' ';
//	cout<<endl;
//	for(int i=0;i<=tot;i++) cout<<cnt[i]<<' ';
//	cout<<endl;
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		same1=-1;
		same2=s1.size();
		for(int j=s1.size()-1;j>=0;j--){
			if(s1[j]==s2[j]) same2=j;
			else break;
		}
		for(int j=0;j<s1.size();j++){
			if(s1[j]==s2[j]) same1=j;
			else break;
		}
//		printf("%d %d\n",same1,same2);
		cout<<query(s1)<<endl;
	}
	return 0;
} 
