#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
const int mod=998244353;
int n;
int ans=0;
int a[maxn];
void dfs(int num,int sum,int maxsum){
	if(num>n){
		return ;
	}
	if(num<3){
		dfs(num+1,sum+a[num],max(sum,a[num]));
	}else{
		if(sum>maxsum){
			ans++;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		ans=0;
	}else if(n==3){
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))){
			ans=1;
		}else{
			ans=0;	
		} 
	}else{
		dfs(1,a[1],a[1]);
	}
	cout<<ans<<"\n";
	return 0;
}
