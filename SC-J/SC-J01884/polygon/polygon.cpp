#include<cstdio> 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int N = 5005;
long long n, ans, a[N], num[N], kok, M = 998244353, con = 0;
void fun(int c, int b, int l, int r){
	if(r <= 0 || b <= 0) return ;
	long long ko = 0;
	ko += a[c]; ko += a[b];
	for(int j = b-1-(l-r)-1; j >=1; j--){
		ko = (ko + a[j])%M;
		if(ko > a[c]*2 && 1+b-j+1-(l-r)-1 >= 3){
			ans = (ans + num[j-1])%M;
			break;
		}else if(j == 1){
			return ;
		}
	}
	fun(c, b, l, --r);
	return ;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	num[0] = 1;
	cin>>n;
	for(int i = 1; i <=n; i++){
		cin>>a[i];
		num[i] = (num[i-1]*2)%M;
	}
	sort(a+1, a+1+n);
	for(int i = n; i >=1; i--){
		kok = 0;
		if(con!=0){
			++i;
		}
		fun(i, i-con-1, i-con-2, i-con-2);
		kok += a[i];
		for(int j = i-con-1; j >=1; j--){
			kok = (kok + a[j])%M;
			if(kok > a[i]*2 && i-j+1-con >= 3){
				ans = (ans + num[j-1])%M;
				con++;
				break;
			}else if(j == 1){
				con = 0;
				break;
			}
		}
	}
	cout<<ans%M;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 