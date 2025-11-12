#include<bits/stdc++.h>
using namespace std;
string a;
long long q,m,man,ans;
bool c[505]={0};
long b[505];
void dfs(long long r,long long n,long long ans){
	if(r>=q){
		return;
	}
	if(ans>=m){
		man++;
		man=man%998224353;
	}
	if(a[r]=='1'){
		for(int i=0;i<q;i++){
			if(b[i]-n>0){
				ans++;c[i]=1;
				dfs(r+1,ans,n);
				ans--;c[i]=0;
			}else{
				for(int i=0;i<q;i++){
					if(c[i]==0){
						c[i]=1;
						dfs(r+1,ans,n+1);
						c[i]=0;
					}
				}
			}
		}
	}else{
		for(int i=0;i<q;i++){
			if(c[i]==0){
				c[i]=1;
				dfs(r+1,ans,n+1);
				c[i]=0;
			}
		}
	}
	return ;
};
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>q>>m;
	cin>>a;
	for(int i=0;i<q;i++){
		cin>>b[i];
	}
	dfs(0,0,0);
	cout<<man%998224353/4<<endl;
	return 0;
}
