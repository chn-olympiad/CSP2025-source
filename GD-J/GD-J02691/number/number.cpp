#include<iostream>
#include<algorithm>
using namespace std;
long long int a[1000005];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	long long int n = s.size();
	long long int temp=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[temp]=s[i]-'0';
			temp++;
		}
	}
	sort(a,a+temp);
	for(int i=temp-1;i>=0;i--){
		cout << a[i];
	}
	return 0;
}
