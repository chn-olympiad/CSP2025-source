#include<iostream>
#include<algorithm>

using namespace std;

int a[10001];
int b[10001];
int n,ans=0;

void dfs(int total,int len,int l){
	if(total==len){
		int sum=0;
		for(int i=1;i<len;i++){
			sum+=b[i];
		}
		if(b[len]<sum){
			ans++;
		}
		return;
	}
	for(int i=l+1;i<=n;i++){
		b[len+1]=a[i];
		dfs(total,len+1,i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		dfs(i,0,0);
	}
	cout<<ans;
	return 0;
} 
