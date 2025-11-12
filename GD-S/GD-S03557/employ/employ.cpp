#include<bits/stdc++.h>
using namespace std;
long long n,m,x=1,sum;
long long ans=1;
string s; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	//只判断特殊情况A
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++){
		int c;
		cin >> c;
		ans=(ans*x)%998244353;	
		x++;
		
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

