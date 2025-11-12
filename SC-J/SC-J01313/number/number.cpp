#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+10;

string str;
int lenn;
int a[N],pt=1;

bool cmp(int a,int b){
	return a > b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> str;
	lenn = str.length();
	for(int i = 0;i < lenn;i++){
		if(str[i] <= '9' && str[i] >= '0'){
			a[pt] = str[i] - '0';
			pt++;
		}
	}
	sort(a+1,a+pt,cmp);
	for(int i = 1;i < pt;i++){
		cout << a[i];
	}
	return 0;
}