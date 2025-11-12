#include <bits/stdc++.h>
using namespace std;
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
bool cmp(int a,int b) {
	return a>b;
}
int arr[1000010];
int main() {
    int k=0;
    string str;
	cin >> str;
	for(int i=0;i<str.size();i++) {
        if(isdigit(str[i])) {
            arr[k]=(str[i]-'0');
            k++;
        }
	}
	sort(arr,arr+k,cmp);
	for(int i=0;i<k;i++) {
        cout << arr[i];
	}
	return 0;
}
