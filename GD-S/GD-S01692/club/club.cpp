//s组骗分：A
//每个部门分到的人数<=n/2 
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm> 
using namespace std;

const int N = 1e5 + 10;
int t,n,ans;
int sat[N];

bool cmp(int x,int y){
	return x > y;
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	while(t--){
		cin >> n;
		int a,b;//A
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				cin >> sat[i] >> a >> b;//A
			} 
		}
		//A(5分):a[i][2],a[i][3]均为0:只用考虑a[i][1],将a排序后取前一半即可 
		
		sort(sat + 1,sat + n + 1,cmp);
		for(int i = 1;i <= n / 2;i++) ans += sat[i];
		cout << ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
