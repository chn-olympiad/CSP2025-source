#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[3][N];
bool flag1;
bool cmp(int x,int y){
	return x>y;
}
int f(int x,int* use,int s){
	if(x>n){
		return s;
	}
	int res=0;
	if(use[0]<n/2){
		int t[3]={use[0]+1,use[1],use[2]};
		res=max(res,f(x+1,t,s+a[0][x]));
	}
	if(use[1]<n/2){
		int t[3]={use[0],use[1]+1,use[2]};
		res=max(res,f(x+1,t,s+a[1][x]));
	}
	if(use[2]<n/2){
		int t[3]={use[0],use[1],use[2]+1};
		res=max(res,f(x+1,t,s+a[2][x]));
	}
	return res;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		flag1=true;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[0][i] >> a[1][i] >> a[2][i];
			flag1=(flag1&&(a[1][i]==0&&a[2][i]==0));
		}
		if(flag1){
			int sum=0;
			sort(a[0]+1,a[0]+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				sum+=a[0][i];
			}
			cout << sum;
			return 0;
		}
		int t[3]={0,0,0};
		cout << f(1,t,0) << endl;
	}
}
