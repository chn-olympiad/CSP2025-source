

#include <bits/stdc++.h>

using namespace std;
int n,m;
string s;
int c[1000];
bool used[100];
int p[1000];
int ans=0;
void solve(){
	int giveup=0;
	int succues=0;
	for(int i=1;i<=n;i++){
		
		//printf("%d ", p[i]);
	}
	//printf("\n");
	for(int i=1;i<=n;i++){
		
		int person = p[i];
		if(giveup>=c[person]){
			giveup++;
			continue;
		}
		
		if(s[i]=='0'){
			giveup++;
			continue;
		}
		
		if(s[i]=='1'){
			succues++;
			continue;
		}
	}//printf("%d ", succues);
	if(succues>=m)ans++;
	//printf("\n");
}

void dfs(int k){
	if(k==n+1){solve();return;}
	
	for(int i=1;i<=n;i++){
		if(!used[i]){
			p[k]=i;
			used[i]=true;
			dfs(k+1);
			used[i]=false;
		}
	}
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    
    
    cin>>n>>m;
	
	cin>>s;
	s="0"+s;
	
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	
	dfs(1);
	printf("%d\n",ans);
    return 0;
}
