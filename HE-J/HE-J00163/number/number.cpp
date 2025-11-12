#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

string s,n;

int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> s;
	for(auto &a:s){
		if(isdigit(a)) n += a; 
	}
	vector<int> arr(n.size());
	for(int i = 0;i<n.size();++i) arr[i] = n[i]-'0';
	for(int i = 1;i<n.size();++i){
		for(int j = 0;j<i;++j){
			if(arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for(auto &v:arr) cout << v;
}
