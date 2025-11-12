#include<bits/stdc++.h>
using namespace std;
int a[1000010],j;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if (s[i]<='9'&&s[i]>='0'){
			j++;
			a[j]=s[i]-'0';
		}
	}
	sort(a+1,a+j+1);
	if (a[j]==0){
		cout << 0;
		return 0;
	}
	for(int i=j;i>=1;i--){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
