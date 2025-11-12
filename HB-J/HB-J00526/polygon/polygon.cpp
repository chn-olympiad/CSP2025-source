#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans,a[5007],b[5005];
void dfs(int s,int x){
	if(s>n||x>n) return;
	if(s>2){
		int f=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				f=a[i];
				cnt+=a[i];
			}
		}
		if(cnt>f*2){
			for(int i=1;i<=n;i++){
				if(b[i]==1){
					cout<<a[i]<<' ';
				}
			}
			cout<<endl;
			ans++;
			ans%=mod;
		}
	}
	b[x]=1;
	dfs(s+1,x+1);
	b[x]=0;
	for(int i=1;i<=n-x+1;i++){
		b[x+i]=1;
		dfs(s,x+i);
		b[x+i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,1);
/*	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++){
			cnt+=a[j];
			cout<<a[j]<<"erge   ";
			if((j-i+1)>=2){
				if(cnt>a[j]*2){
					ans++;
					cout<<cnt<<"wrfw\n";
					ans%=mod;
				}
			}
		}
	}*/
	cout<<ans;
	return 0;
}
