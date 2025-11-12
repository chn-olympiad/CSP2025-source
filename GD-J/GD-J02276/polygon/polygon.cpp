#include<bits/stdc++.h>
using namespace std;

int n;
int num[6000];
int history[1000000][3];
const int mod = 998244353;

//int mmax(int m){
//	int m = -10;
//	for(int i = 0;i < m;i++){
//		if(num[i] > m){
//			m = num[i];
//		}
//	}
//}

int al(int m){
	int a=0;
	for(int i = 0;i < m;i++){
		a += num[i];
	}
	return a;
}

int dp(int q,int cut){
	//cout << "q:" << q << " , " << "cut:" << cut << "\n"; 
	if(history[q][cut]!=0){
		return history[q][cut];
	}
	int maxx = num[q];
	int all = al(q)-cut;
	if(q==n && all > maxx *2){
		return 1;
	}
	else if(q==n && all <= maxx * 2){
		return 0;
	}
	return dp(q+1,cut)%mod + dp(q+1,cut+num[q+1])%mod;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> num[i];
	}
	sort(num,num+n);
//	for(int i = 0;i < n;i++){
//		cout << "num[" << i << "] = " << num[i] << "\n";
//	}
	cout << dp(3,0); 

	return 0;
}

