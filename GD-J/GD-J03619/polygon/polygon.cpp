#include <bits/stdc++.h>
using namespace std;

long long n,a[5005];
long long mx = -1;
long long ans=0,sum=0;

void main2(){
	cin >> n;
	if(n<3){
		cout << 0;
		return;
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum += a[i];
		mx = max(a[i],mx);
	}if(mx == 1){
		for(int i=1;i<=n;i++){
			ans+=i;
		}
		cout << ans;
		return ;
	}
	if(n == 3){
		if(sum > 2*mx) cout << 1;
		else cout<<0; 
	}
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	main2();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
