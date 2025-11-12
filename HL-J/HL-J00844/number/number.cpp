#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >>s;
	int ii=0;
	int n=s.size();
	for(int i=0;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[ii]=s[i]-'0';
			ii++;
		}
	}
	sort(a,a+ii);
	for(int i=ii-1;i>=0;i--){
		cout <<a[i];
	}
	return 0;
}

