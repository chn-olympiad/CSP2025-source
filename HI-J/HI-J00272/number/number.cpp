#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
string str;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k = 0;
	cin>>str;
	int len = str.size();
	for(int i = 0;i<len;i++){
		if(str[i] >= '0' && str[i] <= '9'){
			a[k] = str[i] - 48;
			k++;
		}
	}
	for(int i = 0;i<k;i++){
		sort(a,a+k);
	}
	for(int i = k - 1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}

