#include <bits/stdc++.h>
using namespace std;
const int N=5010;
int a[N],n,cnt,book[N];
void DFS(int num,int ans,int sum){
	if(num>=3 && sum>ans*2){
		//cout<<num<<' '<<ans<<' '<<sum<<endl;
		cnt++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(book[i]==0){
			book[i]=1;
			DFS(num+1,max(ans,a[i]),sum+a[i]);
			//book[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int ans=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	if(n==3){
		for(int i=1;i<=n;i++){
			sum+=a[i];
			ans=max(ans,a[i]);
		}			
		if(sum>ans*2) cout<<1;
		else cout<<0;
	}else if(a[1]==1){
		for(int i=3;i<=n;i++){
			sum+=n/i;
		}
		cout<<sum;
	}else{
		DFS(0,-1,0);
		cout<<cnt;
	}
	return 0;
}