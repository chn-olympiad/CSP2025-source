#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int s[505],c[505],cur[505];
long long ans=0;

void dfs(int num){
	if(num==n+1){
		int rej=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(c[cur[i]]<=rej){
					rej++;
					continue;
			}
			if(s[i]==0){
				rej++;
			}
			else{
				cnt++;
			}
		}
		if(cnt>=m){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		bool flag=1;
		for(int j=1;j<num;j++){
			if(i==cur[j]) flag=0;
		}
		if(flag==1){
			cur[num++]=i;
			dfs(num);
			num--;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	///
	string ss;
	cin>>n>>m;
	cin>>ss;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		if(ss[i]=='1') s[i+1]=1;
		else s[i+1]=0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
