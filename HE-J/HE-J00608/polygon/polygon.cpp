#include<iostream>
using namespace std;
const int mod=998244353;
int n,ans;
int a[5005];
void dfs(int now,int num,int maxn,int tot){
	if(num<0||num>n){
		return ;
	}
	//cout<<now<<" "<<num<<" "<<maxn<<" "<<tot<<endl;
	if(num==0&&tot>maxn*2){
		//cout<<"this is ok:"<<maxn<<" "<<tot<<endl;
		ans++;
		return ;
	}
	for(int i=now+1;i<=n;i++){
		dfs(i,num-1,max(maxn,a[i]),tot+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]>a[3]||a[2]+a[3]>a[1]||a[1]+a[3]>a[2]){
			cout<<1;
			return 0;
		}
	}
	for(int i=3;i<=n;i++){
		dfs(0,i,0,0);
	}
	cout<<ans;
	return 0;
}
