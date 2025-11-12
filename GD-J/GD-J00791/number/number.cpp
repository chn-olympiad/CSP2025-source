#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int a[N],sum;

bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int n = s.size();
	for(int i=0; i<n; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[i+1] = s[i] - '0';
			sum++;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=sum; i++){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
