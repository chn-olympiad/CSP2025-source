#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
bool twp(long long a,long long b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long n = 1;
	cin >> s;
	long long l = s.size();
	for(long long i = 0;i < l;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[n] = s[i]-'0';
			n++;
		}
	}
	if(l == 1){
		cout << a[n-1];
		return 0;
	}
	sort(a+1,a+n+1,twp);
	for(long long i = 1;i < n;i++){
		cout << a[i];
	}
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
