#include<bits/stdc++.h>;
using namespace std;
string s;
int j=1,a[1000005];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len = s.length();
	for(int i = 0;i < len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[j] = s[i]-48;
			j++;
		}
	}
	sort(a+1,a+j,cmp);
	for(int i = 1;i < j;i++){
		cout << a[i];
	}
	return 0;
}
