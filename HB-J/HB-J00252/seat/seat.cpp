#include <bits/stdc++.h>
using namespace std;
int n,m,x=1,y=1,sum[105],ans,idx;
bool cmp(int a1,int a2){
	return a1>a2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>sum[i];
		if(i==1){
			ans=sum[i];
		}
	}
	sort(sum+1,sum+(n*m),cmp);
	for(int i=1;i<=n*m;i++){
		if(sum[i]==ans){
			idx=i;
			break;
		}
	}
	for(int i=2;i<=idx;i++){
		if(x%2==1){
			if(y+1>n){
				x++;
			}else{
				y++;
			}
		}else{
			if(y-1==0){
				x++;
			}else{
				y--;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
