#include <bits/stdc++.h>
using namespace std;

string s;
long long a[10000005];
int cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int l = s.size();
	int j = 1;
	for(long long i = 0;i < l;i ++){
		if(s[i]-'0' >= 0 && s[i] - '0' <=  9){
			a[j] = int(s[i]-'0');
			j ++;
		}
	} 
	sort(a+1,a+j+1,cmp);
	for(long long i = 1;i < j;i ++){
		cout << a[i];
	}
	
	
	return 0;
}
