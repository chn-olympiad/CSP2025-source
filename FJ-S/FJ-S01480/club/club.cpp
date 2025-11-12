#include<iostream>
using namespace std;
int T;
int num[100000][5];
int n;
int dfs(int tot,int dth,int r1,int r2,int r3){
	if(dth>n){
//		cout<<"      "<<tot<<endl;
		return tot;
	}
	int a,b,c;
	if(r1+1<=n/2){
//		cout<<1;
		a=dfs(tot+num[dth+1][1],dth+1,r1+1,r2,r3);
	}
	if(r2+1<=n/2){
//		cout<<2;
		b=dfs(tot+num[dth+1][2],dth+1,r1,r2+1,r3);
	}
	if(r3+1<=n/2){
//		cout<<3;
		c=dfs(tot+num[dth+1][3],dth+1,r1,r2,r3+1);
	}
	return max(a,max(b,c));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int time=1;time<=T;time++){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>num[i][1]>>num[i][2]>>num[i][3];
		cout<<dfs(0,0,0,0,0)<<endl;
	}
}

