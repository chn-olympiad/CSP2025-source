#include <bits/stdc++.h>
using namespace std;
#define in(s) freopen(s,"r",stdin)
#define out(s) freopen(s,"w",stdout)
const int N = 1E6+5;

string s;
int len;
int arr[N];
int n;

int main(){
	in("number.in");
	out("number.out");
	cin >> s;
	len = s.size();
	for(int i=0;i<len;i++)
		if ('0' <= s[i] && s[i] <= '9')
			arr[++n] = s[i]-'0';
	sort(arr+1,arr+n+1);
	for(int i=n;i>=1;i--){
		printf("%d",arr[i]);
	}
	
	return 0;
}
