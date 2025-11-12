#include<bits/stdc++.h>
#define int long long
using namespace std;
int arr[12][12],cost[105];
int n,m;
void sort1(){
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<i;j++){
			if(cost[j]<cost[i])swap(cost[i],cost[j]);
		}
	}
}
bool cmp(int a,int b){
	return a>b?1:0;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>cost[i];
	int x=cost[1];
	int cnt=1;
	//sort1();
	sort(cost+1,cost+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				arr[i][j]=cost[cnt];
				cnt++;
			}	
		}else{
			for(int j=n;j>=1;j--){
				arr[i][j]=cost[cnt];
				cnt++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(arr[i][j]==x){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	return 0;
}

