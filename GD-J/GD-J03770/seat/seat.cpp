#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	cin >> n>>m;
	for (int i =1;i <= n*m;i++){
		cin >> a[i];
	}
	int r = a[1];
	sort(a+1,a+n*m+1,cmp);
	int km=0,start = 0;
	while(a[start +n] > r){
		start += n;
		km++;
	}
	if (km %2==1){
		start++;
		int kn = n;
		for (int i = n;a[start]!=r;i--){
			start++;
			kn--;
		}
		cout << km+1 << ' ' << kn;
	}else{
		start++;
		int kn = 1;
		for (int i = 1;a[start]!=r;i++){
			start++;
			kn++;
		}
		cout << km+1 << ' ' << kn;
	}
	return 0;
} 
