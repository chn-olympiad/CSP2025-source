#include<bits/stdc++.h>

using namespace std;

int a[1000005], cnt = 0;

bool CMP(int x,int y){
	return x > y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin >> s;
	for(int i = 0;i < int(s.length());++i){
		if(s[i] >= '0' && s[i] <= '9'){
			a[cnt++] = s[i] - '0';
		}
	}
	sort(a,a + cnt,CMP);
	for(int i = 0;i < cnt;++i){
		cout << a[i];
	}
	cout << endl;
	return 0;
}
