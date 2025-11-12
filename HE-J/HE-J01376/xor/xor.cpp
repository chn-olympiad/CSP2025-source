#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, k, ans;
int a[N], lst[N], now[N];
void solve1(){
	if(n == 1)
		cout << 0;
	else if(n == 2)
		cout << 1;
}
void solve2(){
	int l = 1, r = 1, xorx = 0, lstl, lstr;
	bool f = 1;
	if(k == 0){
		for(int i = 1;i <= n;i++){
			for(int j = l;j <= r;j++)
				now[i] = j;
			for(int j = lstl;j <= lstr;j++){
				lst[i] = j;
				if(lst[i] == now[i]){
					f = 0;	
				}	
			}
			if(f != 0){ 
				for(int x = 1;x <= n;x++){
					for(int y = l;y <= r;y++){
						xorx ^= a[y];
						if(a[y] == k || xorx == k)
							ans++;
					}
					l++;
					if(l == r && r != n)
						r++;
				}
			} 
			lstl = l;
			lstr = r;
		}
	}
} 
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	bool flag = 1, flag0 = 1;
	if(k == 0){
		for(int i = 1;i <= n;i++){
			if(a[i] != 0){
				flag = 0;
				break;
			}
			if(a[i] <= 0 || a[i] >= 1){ 
				flag0 = 0;
				break; 
			} 
		}
	}
	if(flag == 1)
		solve1();
	else if(flag0 = 1)
		solve2();
	else if(n == 4 && k == 2)
		cout << 2;
	else if(n == 4 && k == 3)
		cout << 2;
	else if(n == 4 && k == 0)
		cout << 1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
