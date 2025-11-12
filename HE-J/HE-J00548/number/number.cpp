#include<bits/stdc++.h>
using namespace std;
string number;
const int N = 1e6 + 3;
int num[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>number;
	int q = number.size(),w = 0;
	for(int i = 1;i <= q;i++){
		if(number[i-1]>='0' && number[i-1]<='9'){
			num[i] = number[i-1] - '0';
			w++;
		}
	}
	for(int i = 1;i <= q;i++){
		for(int j = 1;j <= q-i;j++){
			if(num[j] < num[j+1]) swap(num[j],num[j+1]);
		}
	}
	for(int i = 1;i <= w;i++){
		cout<<num[i];
	}
	return 0;
}
