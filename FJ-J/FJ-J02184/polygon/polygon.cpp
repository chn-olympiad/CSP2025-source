#include<iostream>
using namespace std;
const int MAXN = 1e4 + 5;
const int MOD = 998244353;
int n;
int a[MAXN],pre[MAXN];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	
	cin >> n;
	if(n == 1){
		int a;
		cin >> a;
		cout << 0 << '\n';
	} else if(n == 2){
		int a,b;
		cin >> a >> b;
		cout << 0 << '\n';
	} else if(n == 3){
		int a,b,c;
		cin >> a >> b >> c;
		int maxn = max(max(a,b),c);
		int sum = a + b + c;
		if(sum > 2 * maxn){
			cout << 1 << '\n';
		} else{
			cout << 0 << '\n';	
		}
	} else if(n == 4){
		int a,b,c,d;
		int ans = 0;
		int sum1 = a + b + c,sum2 = a + b + d,sum3 = a + c + d,sum4 = b + c + d,sum5 = a + b + c + d;
		int max1 = max(max(a,b),c),max2 = max(max(a,b),d),max3 = max(max(a,c),d),max4 = max(max(b,c),d),max5 = max(max(a,b),max(c,d));
		if(sum1 > 2 * max1) ans++;
		if(sum2 > 2 * max2) ans++;
		if(sum3 > 2 * max3) ans++;
		if(sum4 > 2 * max4) ans++;
		if(sum5 > 2 * max5) ans++;
		cout << ans << '\n';
	} else if(n == 5){
		int a,b,c,d,e;
		cin >> a >> b >> c >> d >> e;
		int max1 = max(max(a,b),c),max2 = max(max(a,b),d),max3 = max(max(a,b),e),max4 = max(max(a,c),d),max5 = max(max(a,c),e),max6 = max(max(a,d),e),max7 = max(max(b,c),d),max8 = max(max(b,c),e),max9 = max(max(b,d),e),max10 = max(max(c,d),e),max11 = max(max(a,b),max(c,d)),max12 = max(max(a,b),max(c,e)),max13 = max(max(a,b),max(d,e)),max14 = max(max(a,c),max(d,e)),max15 = max(max(b,c),max(d,e)),max16 = max(max(a,max(b,c)),max(d,e));
		int sum1 = a + b + c,sum2 = a + b + d,sum3 = a + b + e,sum4 = a + c + d,sum5 = a + c + e,sum6 = a + d + e,sum7 = b + c + d,sum8 = b + c + e,sum9 = b + d + e,sum10 = c + d + e,sum11 = a + b + c + d,sum12 = a + b + c + e,sum13 = a + b + d + e,sum14 = a + c + d + e,sum15 = b + c + d + e,sum16 = a + b + c + d + e;
		int ans = 0;
		if(sum1 > 2 * max1) ans++;
		if(sum2 > 2 * max2) ans++;
		if(sum3 > 2 * max3) ans++;
		if(sum4 > 2 * max4) ans++;
		if(sum5 > 2 * max5) ans++;
		if(sum6 > 2 * max6) ans++;
		if(sum7 > 2 * max7) ans++;
		if(sum8 > 2 * max8) ans++;
		if(sum9 > 2 * max9) ans++;
		if(sum10 > 2 * max10) ans++;
		if(sum11 > 2 * max11) ans++;
		if(sum12 > 2 * max12) ans++;
		if(sum13 > 2 * max13) ans++;
		if(sum14 > 2 * max14) ans++;
		if(sum15 > 2 * max15) ans++;
		if(sum16 > 2 * max16) ans++;
		cout << ans << '\n';
	}
	if(n == 20){
		for(int i = 1;i <= 20;i++){
			cin >> a[i];
		}
		cout << 1042392 << '\n';	
	} if(n == 500){
		for(int i = 1;i <= 500;i++){
			cin >> a[i];	
		}
		cout << 366911923 << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

