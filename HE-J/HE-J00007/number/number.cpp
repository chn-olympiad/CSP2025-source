#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
int a[100005]={},cnt=0;
bool cmp(int a1,int b){
	return a1>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("numeber.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i]>='0' && s[i] <= '9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i = 1;i <= cnt;i++){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
