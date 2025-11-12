#include<bits/stdc++.h>
using namespace std;
int arr[10001];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int k = a.size();
	for(int i = 0;i<k;++i){
		if(a[i]>='0'&&a[i]<='9'){
			int x = a[i]-'0';
			arr[x]++;
		}
	}
	for(int i = 9;i>=0;--i){
		for(int j = 0;j<arr[i];++j){
			cout<<i;
		}
	}
	return 0;
}
