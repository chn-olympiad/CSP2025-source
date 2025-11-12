#include<bits/stdc++.h>
using namespace std;
long long moll=998244353;
int m,n;
int a[550],flag[550];
string t;
long long ans;
void dfs(int r,int c,int y,int l){
	if(c==n){
		if(y>=m){
			ans++;
			ans=ans%moll;
		}else{
			if(a[r]>l&&t[c-1]=='1'){
				ans++;
				ans=ans%moll;
			}
		}
	}else{
		if(a[r]>l){
			if(t[c-1]=='1'){
				for(int i=1;i<=n;i++){
					if(flag[i]!=1){
						flag[i]=1;
						dfs(i,c+1,y+1,l);
						flag[i]=0;
					}
				}
				
			}else{
				for(int i=1;i<=n;i++){
					if(flag[i]!=1){
						flag[i]=1;
						dfs(i,c+1,y,l+1);
						flag[i]=0;
					}
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(flag[i]!=1){
					flag[i]=1;
					dfs(i,c+1,y,l+1);
					flag[i]=0;
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int kk=1;
	for(int i=0;i<n;i++){
		if(t[i]!='1'){
			kk=0;
			break;
		}
	}
	if(kk==1){
		ans=1;
		for(int i=n;i>=1;i--){
			ans*=i;
			ans=ans%moll;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		flag[i]=1;
		dfs(i,1,0,0);
		flag[i]=0;
	}
	cout<<ans%moll;
	return 0;
}

