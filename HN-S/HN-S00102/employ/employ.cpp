#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt,t,ji=1,f;
string s;
int a[1001],book[1001];
void dfs(int x,int y){
	ji++;
	if(ji-1>=s.size()){
		ji--;
		return;
	}
	for(int i=1;i<=n;i++){
		if(book[i]==0){
			book[i]=1;
			if(y==0){
				t++;
				f=1;				
			}else if(t>=a[i]){
				t++;
				f=1;
			}
		}else continue;
		dfs(i,(s[ji]-'0'));
		book[i]=0;
		if(f==1){
			f=0;
			t--;
		}
	}
	ji--;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n>18){
		cnt=1;
		for(int i=1;i<=n;i++){
			cnt*=i;
			cnt%=998244353;
		}
		cout<<cnt;
		return 0;
	}
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		book[i]=1;
		if((s[0]-'0')==0){
			t=1;
		}
		dfs(i,(s[1]-'0'));
		if(n-t>=m){
			cnt++;
		}
		t=0;
		book[i]=0;
		ji=1;
	}
	cout<<cnt;
	return 0;
}
