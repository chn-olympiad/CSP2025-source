#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
using namespace std;
using ll = long long;
char s[1000005];
ll mark[10];

int main(void){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i=0; i<(int)strlen(s); ++i)
		if(isdigit(s[i])){
			const ll ind = s[i]-'0';
			++mark[ind];
		}
	for(int i=9; i>=0; --i)
		for(int j=1; j<=mark[i]; ++j)
			cout << i;
	return 0;
}

/*
11/01 8:23 freopen freopen freopen
11/01 8:29 im tense now
11/04 8:44 T1 finished
11/04 10:28 T1 checked-correct
exp. 100pts

[
-It's (not)easy to be a 1= person.
-Easier said than done.
-Well, actions speak louder than words.
]

subscribe Astralyn_S plz ^-^(FJ-J00987)
*/
