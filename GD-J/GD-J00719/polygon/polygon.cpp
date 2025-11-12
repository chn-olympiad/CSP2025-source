#include <bits/stdc++.h>
using namespace std;

int n,a[5009];
long long sum,cnt;
void check(int m,int begin,int mx){
	if(m == 3){
		for(int i=begin;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					if(sum + a[i] + a[j] + a[k] > max(max(mx,a[i]),max(a[j],a[k])) * 2) cnt++;
				}
			}
		}
		return;
	}
	for(int i=begin;i<=n-m+1;i++){
		sum += a[i];
		check(m-1,i+1,max(mx,a[i]));
		sum -= a[i];
		cnt %= 998244353;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	bool flag = 1; 
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) 
		if(a[i] != 1) flag = 0;
	
	if(!flag){
		for(int i=3;i<=n;i++){
			check(i,1,0);
		}
		cout << cnt;
	}else{
		for(int i=3;i<=n;i++){
			long long x=n-i,res=1;
			for(int j=1;j<=i;j++){
				res *= n-j+1;
			}
			for(int j=1;j<=i;j++){
				res /= j;
			}
			cnt += res % 998244353;
		}
		cout << cnt;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
