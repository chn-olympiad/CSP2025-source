#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000005];
int z;
int ind = 1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	z = s.size();
	for(int i = 0;i < z;i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[ind] = s[i] -'0';
			ind ++;
//			cout << a[ind - 1];
		}
	}
	sort(a + 1,a + ind);
//	cout << endl;
	for(int i = ind - 1;i >= 1;i --){
		cout << a[i] ;
	}
	return 0;
}
