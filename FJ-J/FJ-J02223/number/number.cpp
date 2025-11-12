#include<bits/stdc++.h>
using namespace std;
int arr[10000005];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long cum=0;
	for(int i=0; i<s.size(); i++) {
		if(s[i]<='9' && s[i]>='0') {
			arr[cum]=s[i];
			cum++;
		}
	}
	sort(arr,arr+cum,cmp);
	for(int i=0; i<cum; i++) {
		cout<<char(arr[i]);
	}
	return 0;
}
