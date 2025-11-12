#include<bits/stdc++.h>
using namespace std;

string s;
int n[1000010],num[11],sum = 0;

int main(){ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0;i <= 9;i++)	num[i] = i;
	int l = s.size();
	
	for (int i = 0;i < l;i++){
		bool nu = false;
		for (int j = 0;j <= 9;j++)
			if (s[i] - '0' == num[j])	nu = true;
		if (nu){
			sum += 1;
			n[sum] = s[i] - '0';
		}
	}
	sort(n,n+sum+1);
	for (int i = sum;i >= 1;i--)  cout << n[i];
	return 0;
} 
