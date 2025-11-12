#include<bits/stdc++.h>
using namespace std;
long long b[1086][1086],a[10086];
long long n,m,ans,inp;
bool flag = true;
bool flag2 = false;
int main(){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n*m;i++){
		cin>>a[i];
	}
	inp = a[1];
	sort(a+1,a+n*m+1,greater<long long>());
	int k = 0,d = 0,q = 1;
	while (k <= n*m){
		if (flag == true){
			d += 1;
		}else{
			d -= 1; 
		}
		k += 1;
		b[d][q] = a[k];
		if (d == n){
			q += 1;
			k += 1;
			b[d][q] = a[k];
			flag = false;
		}else if (d == 1 and flag2 == true){
			q += 1;
			k += 1;
			b[d][q] = a[k];
			flag = true;
		}
		flag2 = true;
	}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= m;j++){
			if (b[i][j] == inp){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
