#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,c[1005],id[1005],s1,m,zer;
char s[1005];
deque<int> p;
void pa(){
	for(int i=p.size()-1;i>=0;i--){
		//cout<<p[i]<<" ";
	}
//	cout<<endl;
	int pe=0,now=0;
	for(int i=p.size()-1;i>=0;i--){
		if(s[n-i]=='1'){
			if(c[p[i]]>now)pe++;
			else{
				now++;
			}
		}
		else{
			now++;
		}
	}
//	cout<<pe<<endl;
	if(pe>=m)ans++;
	ans%=998244353;
}
void dfs(int dep){
	if(dep==n){
		pa();
		return;
	}
	for(int i=1;i<=n;i++){
		if(id[i]==0){
			 id[i]=1;
			 p.push_front(i);
			 dfs(dep+1);
			 p.pop_front();
			 id[i]=0;
		} 
	} 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	s1=1;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]!='1')s1=0;
	} 
	for(int i=1;i<=n;i++){
		cin>>c[i]; 
		if(c[i]==0)zer++;
	}
	dfs(0);
	cout<<ans;
	return 0;
} 
