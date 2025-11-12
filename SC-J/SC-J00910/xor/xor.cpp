#include<bits/stdc++.h>
using namespace std;

const int N=1048578;
int a[N+10],f[N+10]={0},n;
int cnt=0,maxcnt=0;
void dfs(int k,int x){
	for(int i=k;i<=n;i++){
		if(f[i]^f[k-1]==x){
			cnt++;
			for(int j=i+1;j<=n;j++){
				dfs(i+1,x);
			}
			maxcnt=max(maxcnt,cnt);
			cnt--;
		}
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f[1]=a[1];
	for(int i=1;i<=n;i++)f[i]=a[i]^f[i-1];
	for(int i=1;i<=n;i++){
		dfs(i,k);
	}
	cout<<maxcnt;
	
	
	fclose(stdin);fclose(stdout);
	return 0;
}