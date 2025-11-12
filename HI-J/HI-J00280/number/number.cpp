#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int num[N];

bool cmp(int x,int y){
	return x > y;
}

int main() {
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	string a;
	cin >> a;
	
	int f = 1;
	for(int i = 0; i < a.size(); i++){
		if(a[i] >= '0' && a[i] <= '9'){
			num[f] = a[i] - '0';
			f++;
		}
	}
	
	sort(num+1,num+f,cmp);
	
	for(int i = 1; i < f; i++){
		cout << num[i];
	}

	return 0;
}
