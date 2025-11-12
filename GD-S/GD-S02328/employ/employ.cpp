#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
int n,m;
string ss;
int c[505];
bool v[505];
int cc,s,cnt;
void dfs(int id){
	if(id>n){
		if(s>=m){
			cnt++;
			cnt%=mod;
		}
		cout<<s<<" ";
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			if(cc>=c[i]){
				cc++;
				v[i]=1;
				dfs(id+1);
				v[i]=0;
				cc--;
			}else{
				if(ss[id-1]=='0'){
					cc++;
					v[i]=1;
					dfs(id+1);
					v[i]=0;
					cc--;
				}else{
					s++;
					v[i]=1;
					dfs(id+1);
					v[i]=0;
					s--;
				} 
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>ss;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<cnt;
} 
