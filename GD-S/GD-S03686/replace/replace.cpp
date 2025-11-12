#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q;
struct A{
	string s1,s2;
	int id,pb1,pb2;
}s[200005],t[200005];
bool cmp(A B,A C){
	return B.s1.length()<C.s1.length();
}
int jl=0;
bool checkB(string &k,int &pb){
	int jla=0,jlb=0;
	for(int i=0;i<k.length();i++){
		if(k[i]=='a')jla++;
		if(k[i]=='b'){
			jlb++;
			pb=i;
		}
	}
	if(jlb!=1||jla!=k.length()-1)return 0;
	return 1;
}
ll ans[5000005];
bool vis[5000005];
queue<int>que;
vector<int>vec[5000005];
void solveB(){
	for(int i=1;i<=q;i++){
		for(int l=0;l<t[i].s1.length();l++){
			inq[i]=ans[i]=0;
		}
		vis[t[i].pb2]=1;
		que.push(t[i].pb2);
		while(!que.empty()){
			A k=que.top();
			que.pop();
			for(int l=1;l<=n&&s[l].s1.length()<=t[i].s1.length();l++){
				if(s[l].pb2<=k.pb2){
					
				}
			}
		}
		cout<<ans[t[i].pb2]<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int jla=0,jlb=0;
	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
		if(!checkB(s[i].s1,s[i].pb1))jl=1;
		if(!checkB(s[i].s2,s[i].pb2))jl=1;
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=q;i++){
		cin>>t[i].s1>>t[i].s2;
		t[i].id=i;
		if(!checkB(t[i].s1,t[i].pb1))jl=1;
		if(!checkB(t[i].s2,t[i].pb2))jl=1;
	}
	if(jl==0)solveB();
	return 0;
}
