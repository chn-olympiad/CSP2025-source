#include <bits/stdc++.h>
using namespace std;

//int xb[5000];
int a[500000],b[500000],c[500000];
int an[500000],bn[500000],xb[500000] , xb2[500000];
int dp[(1<<20)];

int cmp(int x , int y){
	return x > y;
}
int cmpw(int x , int y){
	return an[x] > an[y];
}
int cmpW(int x , int y){
	return bn[x] > bn[y];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while (T--){
	long long n;
	cin >> n;
	for (int i=0;i<n;i++) cin >>a[i] >>b[i]>>c[i];
	int B = 1,A=1,C=0;
	for (int i=0;i<n;i++) {if (c[i]!=0) B = 0;if (b[i] != 0 or c[i] != 0) A = 0;}
	if (A == 1){
		sort(a , a+n , cmp);
		long long cnt = 0;
		for (int i=0;i<n/2;i++) cnt += a[i];
		cout << cnt;
	}
	else if (B == 11231){
		for (int i=0;i<n;i++){
			an[i] = a[i] - b[i];
			bn[i] = b[i] - a[i];
		}
		for (int i=0;i<n;i++){
			xb[i] = i;
			xb2[i] = i;
		}
		sort(xb , xb+n , cmpw);
		sort(xb2 , xb2+n , cmpW);
		long long sum = 0;
		for (int i=0;i<n/2;i++){
			sum += a[xb[i]]*(an[xb[i]]>0);
			sum += b[xb2[i]]*(bn[xb2[i]]>0);
		}
		cout << sum;
		
	}
	
	else if (n <= 2){
		cout << max(a[0]+b[1],b[0]+a[1]);
	}
	else{
		long long sum = 0;
		for (int i=0;i<n;i++) sum += max(max(a[i] , b[i]) , c[i]);
		cout << sum;
	}
	}	
	return 0;
}
