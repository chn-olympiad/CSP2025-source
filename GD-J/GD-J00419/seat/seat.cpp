#include<bits/stdc++.h>
using namespace std;

int n,m,a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n*m;i++){
		cin >> a[i];
	}
	int r = a[0];
	int sum = 0;
	sort(a,a+m*n,cmp);
	while(a[sum] != r){
		sum++;
	}
	sum++;
	if(sum%n == 0 and (sum/n)%2 != 0){
		cout << sum/n  << ' ' << n;
	}else if(sum%n == 0 and (sum/n)%2 ==0){
		cout << sum/n  << ' ' << 1;
	}else if(sum%n != 0 and (sum/n+1)%2!=0){
		cout << sum/n +1 << ' ' << sum%n;
	}else if(sum%n != 0 and (sum/n+1)%2==0){
		cout << sum/n +1 << ' ' << n - sum%n + 1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
