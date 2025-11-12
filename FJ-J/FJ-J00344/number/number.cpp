#include <bits/stdc++.h>
using namespace std;
string s;
int j=1,ans=0,k=1;
string c[100000000],a[100000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	ans = s.size();
	for(int i=0;i<=ans;i++){
		if(s[i]>=48 && s[i]<=57){
			a[j] = s[i];
			j++;
		}
	}
	sort(a,a+ans+1);
	for(int j=ans;j>=1;j--){
		c[k] = a[j];
		k++;
	}
	for(int i=1;i<=ans;i++){
		cout << c[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}