# include <bits/stdc++.h>
using namespace std;

int a[1005];
bool cmp(int a, int b){
	return a>b;
}
int main (){
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string s;
	int count= 0;
	cin >> s;
	for(int i=0; s[i]; i++) {
		if(s[i]>='0' && s[i]<='9'){
			a[count] = s[i]-'0';
			count ++;
		}
	}
	sort(a, a+count, cmp);
	for (int i=0; i<count; i++){
		printf("%d", a[i]);
	}
	
	return 0;
}
