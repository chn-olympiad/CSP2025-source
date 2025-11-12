#include <bits/stdc++.h>
using namespace std;
int n,sum=1,a[1000005];
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	n=s.size();
	for (int i=0;i<n;i++){
		if(s[i]>='0' and s[i]<='9'){
			a[sum]=s[i]-'0';
			sum++;
		}
	}
	sort(a+1,a+sum+1,cmp);
	for (int i=1;i<sum;i++)  cout << a[i];
	return 0;
}
