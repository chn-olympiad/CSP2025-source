#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans=0,m=0,cnt=0,res=0;
bool b[5010];
void dfs(int c){
	
	if(res>=3){
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				m=max(m,a[i]);
			}
		}
		if(ans>2*m){
			cnt++;
			return;
		}
	}
	if(res+1<=n){
		ans+=a[c];
		b[c]==1;
		res++;
		dfs(c+1);
		res--;
		ans-=a[c];
		b[c]=1;
	}
	dfs(c+1);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<cnt;
	return 0;
}
