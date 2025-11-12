#include<bits/stdc++.h>
using namespace std;
const int N=505,P=998244353;
int n,m,a[N],path[N],x[N];
char c[N];
bool vis[N];
int ans;
bool F(){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(c[i]=='0' || x[i]<=0){
			for(int j=i+1;j<=n;j++){
				x[j]--;
			}
		}else{
			sum++;
		}
	}
	if(sum>=m) return true;
	else return false;
} 
void search(int t){
	if(t>n){
		for(int i=1;i<=n;i++){
			x[i]=a[path[i]];
		}
		if(F()) ans++;
		ans%=P;
		return ;
	} 
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		path[i]=t;
		search(t+1);
		vis[i]=0; 
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	search(1);
	cout<<ans%P;
	return 0;
} 
