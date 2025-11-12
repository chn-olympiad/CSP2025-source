#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[500010],ans,s,kk;
void dfs(int g){
	for(int i=g;i<=n;i++){
		s^=a[i];
	//	cout<<s<<" ";
		if(s==k){
			//cout<<"aaaa";
			ans++;
			s=0;
		//	dfs(i);
		}
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=2;i<=n;i++){
			if(a[i]==0||a[i]==a[i-1]){
				ans++;
			}
		} 
		cout<<ans;
	}else{
		s=0;
		dfs(1);
	//	cout<<endl;
		cout<<ans;
	}
	return 0;
} 