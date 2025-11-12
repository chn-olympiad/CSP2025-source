#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int ans;
int flag = 1,flag1 = 1;
int mmax,imax,ymax;
struct cry{
	int c;
	int r;
	int y;
}a[100005];
bool cmp(cry x,cry y){
	if(x.c != y.c){
		return x.c > y.c; 
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0;i < n;i++){
			cin>> a[i].c >> a[i].r >> a[i].y;
			if(flag ==1&&a[i].r != 0 && a[i].y != 0){
				flag = 0;
		 }else if(flag1 == 1 && a[i].y != 0){
		 	flag1 = 0;
		 } 
		 if(a[i].c > a[i].r){
		 	imax = max(a[i].c,imax);
		 }else if(a[i].r >= a[i].c){
		 	mmax = max(a[i].r,mmax);
		 }
		}
		if(flag ==1){
			sort(a,a+n,cmp);
			for(int i = 0;i < n/2;i++){
				ans += a[i].c;
				cout << ans << endl;
			}
		}else if(flag1 ==1){
			cout << imax + mmax;
	}else{
	 for(int i = 0;i < n;i++){
	 	if(a[i].r >= a[i].c&&a[i].r >= a[i].y){
	 		ans += a[i].r;
		 }else if(a[i].y >= a[i].c&&a[i].y >= a[i].r){
		 	ans += a[i].y;
		 }else{
		 	ans+=a[i].c;
		 }
	 }
	 cout << ans << endl;
	}
}
	return 0;
} 
