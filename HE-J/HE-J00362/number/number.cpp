#include <bits/stdc++.h>
using namespace std;
int arr[1000005];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int num = 0;
	string s;
	cin>>s;
	for(int i = 0;i< s.size()+1;i++){
		char d = s[i];
		if(d>='0'&&d <='9'){
			arr[num] += d-'0';
			num++;
		}
	}
	sort(arr,arr+num,cmp);
	for(int i = 0;i<num;i++){
		cout<<arr[i];
	}

	return 0;
}
