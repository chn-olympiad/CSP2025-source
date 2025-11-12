#include<bits/stdc++.h>
using namespace std;

string s;
int a[100000010];
long long l;
bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("number.in", "r" ,stdin);
	freopen("number.in", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[l] = s[i] - '0';
			l++;
		}
	}
	sort(a + 1, a + l, cmp);
	for(int i = 1; i < l; i ++){
		cout << a[i];
	}
	
	
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
