#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+n*m+1,cmp);
	int now_i=1,now_j=1,i=1;
	while(1){
		if(a[i]==num){
			cout<<now_i<<" "<<now_j<<endl;
			return 0;
		}
		if(now_j==n&&i%(2*n)==n){
			now_i++;
		}else if(now_j==1&&i%(2*n)==0){
			now_i++;
		}else if(i%(2*n)<n){
			now_j++;
		}else now_j--;
		i++;
	}
}
//by syj