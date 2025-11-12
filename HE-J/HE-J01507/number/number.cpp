#include<bits/stdc++.h>
using namespace std;
string s;
char a[100005];
long long cnt=0;
char cmp(int x,int y){
	return x>y;
}
int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	long long len = s.size();
	for (int i=0 ; i<len ; i++) {
		if (s[i] >= '0' && s[i] <= '9')	{
			 a[i] = s[i];
			 cnt++;
		}  
	}
	sort(a,a+len+1,cmp);
	for (int i=0 ; i<=cnt ; i++) {
	   cout << a[i];
	}
	return 0;
} 
