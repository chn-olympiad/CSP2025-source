#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y;
	cin>>x>>y;
	int num=x*y;
	int a[101]={};
	int in;
	cin>>in;
	a[in]+=2;
	for(int i=0;i<num-1;i++){
		int in;
		cin>>in;
		a[in]++;
	}
	int cnt=1;
	for(int i=100;i>=1;i--){
		if(a[i]==1){
			cnt++;
		}else if(a[i]==2){
			break;
		}
	}
	int ans_x,ans_y;
	ans_x=(cnt-1)/x+1;
	cout<<ans_x;
	if(ans_x%2==1){
		ans_y=cnt-(ans_x-1)*x;
	}else if(ans_x%2==0){
		ans_y=x-(cnt-(ans_x-1)*x)+1;
	}
	cout<<' '<<ans_y;
}