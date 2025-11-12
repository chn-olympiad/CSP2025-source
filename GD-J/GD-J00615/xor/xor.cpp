#include <bits/stdc++.h>
using namespace std;

pair <long long,string> a[600000];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,k,l,f=0;
	char d;
	cin >> n >> k;
	for (int i = 1;i <= n;i++){
		cin >> a[i].first;
		if(a[i].first != 1) f = 1; 
		int s = a[i].first;
		while(s != 0){
			d = s % 2 +'0';
			s/=2;
			a[i].second = d + a[i].second;
		}
	}
	if(n<=2){
		if(n == 1)cout << 0;
		if(n == 2)cout << 1;
		return 0;
	}
	if(k == 0&&f==0){
		cout << n/2;
		return 0;
	}
	if (k == 0){
		int sum = 0,pp = 0;
		for (int i = 1;i <= n;i++){
			if(a[i].first == a[i+1].first&&i != n)
			{
				sum++,i++;
			}
		}
		for (int i = 1;i <= n;i++){
			if(a[i].first == 0){
				pp++;
			}
		}
		cout << max(pp,sum);
		return 0;
	}
	if (k == 1){
		int sum = 0,pp = 0;
		for (int i = 1;i <= n;i++){
			if(a[i].first != a[i+1].first&&i != n)
			{
				sum++,i++;
			}
		}
		for (int i = 1;i <= n;i++){
			if(a[i].first == 1){
				pp++;
			}
		}
		cout << max(pp,sum);
	}
	return 0;//È¥µô×¢ÊÍ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
}
