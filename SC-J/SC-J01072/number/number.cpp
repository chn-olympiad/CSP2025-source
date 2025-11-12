#include<bits/stdc++.h>
using namespace std;

int i,a[1000100],j;
string n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n;
	i = n.size() - 1;
	while(i >= 0){
		a[i] = n[i] - 48;
		i--;
	}
	sort(a,a + n.size());
	i = n.size();
	while(i > 0){
		i--;
		if(a[i] > 9) continue;
		cout << a[i];
	}
	return 0;
}