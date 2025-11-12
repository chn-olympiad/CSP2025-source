#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 5120,mod = 998244353;

int n,a[maxn],ans = 0;

void create(int b,int m,int s,int i,int nb){
	//cout << "b : " << b << " m : " << m << " s : " << s << " i : " << i << "nb : " << nb << endl;  
	if(nb == b){ 
		if(m*2 < s){
			ans ++;
			ans %= mod;
	//		cout << "ans = " << ans << endl;
		}
		return ;
	}
	for(i;i <= n;i++){
	   	create(b,max(m,a[i]),s+a[i],i+1,nb+1);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 3;i <= n;i++){
		create(i,0,0,1,0);
	}
	cout << ans % mod<< endl;
	return 0;
}
