#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+86;
string s,a[N],sa;
long long n,m;
int main(){
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	cin>>s;
	int len = s.size();
	for (int i = 0;i <= len;i++){
		sa = s.substr(i,1);
		if (sa == "0" or sa == "1" or sa == "2" or sa == "3" or sa == "4" or sa == "5" or sa == "6" or sa == "7" or sa == "8" or sa == "9"){
			a[i] = sa; 
		}else{
			a[i] = " ";
		}
	}
	sort(a,a+len,greater<string>());
	for (int i = 0;i <= len;i++){
		if (a[i] == " "){
			continue;
		}else{
			cout<<a[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
