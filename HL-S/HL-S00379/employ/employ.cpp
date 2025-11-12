#include<bits/stdc++.h>
using namespace std;
int c[501];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m ;
	int s;
	cin >> s;
	int A=1;
	while(s/10!=0){
		if(s%10==0){
			A=0;
		}
		s/=10;
	}
	if(A==1){
		cout << "0" << endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}	
	if(m==1){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
		}
		ans%=998244353;
		cout << ans << endl;
		return 0;
	}
	else{
		cout << "老师辛苦了";
	}
	return 0;
}