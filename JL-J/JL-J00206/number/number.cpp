#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000100],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int n=s.size();
	for(int i=0;i<n;++i){
		if(s[i]<='9'&&s[i]>='0'){
			k++;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;--i){
		cout << a[i];
	}
	cout << endl;
	return 0;
}
