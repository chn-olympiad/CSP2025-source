#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000010];
int main ()
{
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	cin >> s;
	int inpet = 0;
	for (int i=0;i<s.size();i++){
		if (s[i] >= '0' && s[i] <= '9'){
			a[inpet] = s[i]-'0';
			inpet++;
		}
	}
	sort (a,a+inpet);
	for (int i=inpet-1;i>=0;i--)cout << a[i];
	return 0;
}
