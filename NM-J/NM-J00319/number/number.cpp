#include <bits/stdc++.h>
using namespace std;
int n;
int ans = 0;
string s;
int a[1000005] = {0};
bool fx(int a,int b)
{
	return a > b;
}
int main(){
	//freopen("nember.in","r","stdin");
	//freopen("nember.out","w","stdout");
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> s;
	}
	if(size.s()==1){
		cout << s[1];
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			a[i] = s[i] - 0;
			ans++;
		}
	}
	sort(a,a+n,fx);
	for(int i=1;i<=ans;i++)
	{
		cout << a[i];
	}
	return 0;
}
