#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],cnt=0;
bool st[5010];
void dfs(int r,int c){
	if(r==0){
		int x=0,max_=0;
		for(int i=1;i<=n;i++){
			if(st[i]==true){
				x+=a[i];
				max_=a[i];
			}
		}
		if(x>max_*2){
			cnt++;
			cnt%=998244353;
		}
		return ;
	}
	for(int i=c;i<=n;i++){
		if(st[i]==false){
			st[i]=true;
			dfs(r-1,i);
			st[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(i,1);
	}
	cout<<cnt;
	return 0;
} 
