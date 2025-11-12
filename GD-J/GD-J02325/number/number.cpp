#include<bits/stdc++.h>
using namespace std;
int a[1000005],j;
bool cmp(int x,int y){
	return x>y;
}
void man(){
	string s;
	cin >> s;
	for (int i = 0;i<s.size();i++){
		if (s[i]>='0' && s[i]<='9') a[++j]=s[i]-'0';
	}
	sort(a+1,a+j+1,cmp);
	for (int i = 1;i<=j;i++) cout << a[i];
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	man();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
