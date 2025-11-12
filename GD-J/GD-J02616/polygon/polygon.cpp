#include<bits/stdc++.h>
using namespace std;
const long long N=5e3+10;
long long n,m,k,arr[N],ans=0;
bool take[1000][1000][1000],tong[N];

void dfs(int sum,int maxx,int c,int xb){
	if(sum>2*maxx&&c>2){
		if(!take[sum][maxx][c]){
			ans++;
			take[sum][maxx][c]++;
			//cout<<sum<<" "<<maxx<<endl;
		}
		
	
	}
	if(xb+1<=n){
		dfs(sum,maxx,c,xb+1);
		dfs(sum+arr[xb+1],arr[xb+1],c+1,xb+1);
	}
	
	
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		tong[i]++;
	}
	sort(arr+1,arr+n+1);
	
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
} 
