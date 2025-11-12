#include<bits/stdc++.h>
using namespace std;
#define long long int
const int N = 1e6+5;
int arr[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt = 0;
	for(int i = 0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[cnt] = s[i]-'0';
			cnt++;
		}
	}
	sort(arr,arr+cnt);
	for(int i = cnt-1;i>=0;i--){
		cout<<arr[i];
	}
	return 0;
}
