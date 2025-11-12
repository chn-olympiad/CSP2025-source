#include<bits/stdc++.h>
using namespace std;
string s;
const int N = 1e6+1000;
int a[N];
int j = 1;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[j++] = s[i]-'0';
		}
	}
	sort(a+1,a+j,cmp);
	
	for(int i = 1; i <= j-1; i++){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
