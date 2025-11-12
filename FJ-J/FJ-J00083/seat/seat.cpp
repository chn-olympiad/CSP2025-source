#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn];
int n,m;
int R;
bool check(int x){
	return a[x] > R;
}
int binary_search(int l,int r){
	while(l<=r){
		int mid = (l+r) / 2;
		if(!check(mid)){
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	return l;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>R;
	for(int i = 0;i<n*m-1;i++){
		cin>>a[i];
	}
	sort(a,a+n*m-1);
//	for(int i = 0;i<n*m-1;i++){
//		cout<<a[i]<<endl;
//	}
	int ans = binary_search(0,n*m-1)+1;
//	cout<<ans<<endl;
	ans = n*m - ans + 1;
	if(ans == 0){
		ans = 1;
	}
//	cout<<ans<<endl;
	int x = ans % n;
	if(x == 0){
		if((ans/n)%2==0){
			cout<<ans/n<<" "<<1;
		}else{
			cout<<ans/n<<" "<<n;
		}
	}else{
		if(((ans-x)/n)%2==0){
			cout<<(ans-x)/n + 1<<" "<< x ;
		}else{
			cout<<(ans-x)/n + 1<<" "<< n-x+1 ;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
