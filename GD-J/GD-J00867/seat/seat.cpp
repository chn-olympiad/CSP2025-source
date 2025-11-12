#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m,arr[N],a;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> arr[i];
	}
	a=arr[1];
	sort(arr+1,arr+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(arr[i]==a){
			int ans_n,ans_m=i/n;
			if(i%n!=0)ans_m++;
			if(ans_m%2!=0)ans_n=(i-1)%n+1;
			else ans_n=n-(i-1)%n;
			cout << ans_m << ' ' << ans_n << endl;
			return 0;
		}
	}
	return 0;
}
