#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) cin >> a[i];
	int cnt=a[1];
	sort(a+1,a+m*n+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i] == cnt){
			if(i%n == 0) cout << i/n << " " << n;
			else if(i/n%2 != 0) cout << i/n+1 << " " << n-i%n+1;
			else cout << i/n+1 << " " << i%n;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
