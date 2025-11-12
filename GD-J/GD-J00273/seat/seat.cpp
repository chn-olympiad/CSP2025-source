#include <iostream>
#include <algorithm>
using namespace std;
int a[1010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++){
		if (sum==a[i]){
			sum=i;
			break;
		}
	}
	int ans=0;
	if (sum%n==0){
		cout << sum/n << " ";
		ans=0;
	}else{
		cout << (sum/n)+1 << " ";
		ans=1;
	}
	int x=sum%n;
	if (ans==0){
		if ((sum/n)+1%2==0){
			cout << 1;
		}else{
			cout << n;
		}
	}else{
		if ((sum/n)%2==0){
			cout << sum%n;
		}else{
			cout << n+1-sum%n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
