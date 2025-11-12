#include<bits/stdc++.h>
using namespace std;
string s;
const int N = 1e6 + 7;
int a[N];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int ind = 1;
	int sum = 0;
	cin>>s;
	for(int i = 0;i < int(s.length());i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			sum ++;
			a[ind] = s[i] - '0';
			ind ++;
		}
	}
	if(sum == 0){
		cout<<0;
		return 0;
	}
	if(sum == 1){
		cout<<a[1];
		return 0;
	}
	sort(a + 1,a + sum + 1,cmp);
	int flag = 1;
	for(int i = 1;i <= sum;i ++){
		if(a[flag] == 0){
			flag ++;
			continue;
		}
		cout<<a[i];
	}
	return 0;
}
