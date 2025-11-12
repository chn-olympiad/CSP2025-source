#include<bits/stdc++.h>
using namespace std;
string s;
long long n,sum;
int a[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	n = s.size();
	//cout << n << endl;
	for(int i=0;i<n;i++,sum++){
		if(s[i]>='0' && s[i]<='9'){
			a[sum] = s[i]-'0';
			//cout << a[sum] << ' ' << i << endl;
		}
	}
	sort(a,a+sum,greater<int>());
	for(int i=0;i<sum;i++){
	    //cout << a[i] << ' ';
	    cout << a[i];
	}
	return 0;
}