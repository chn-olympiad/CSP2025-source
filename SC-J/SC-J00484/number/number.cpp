# include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
bool cmp(int a,int b){return a > b;}
string s;
int  a[N];
bool f;
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int i = 0,j = 1,len = s.size();
	for(i = 0;i < len;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[j++] = s[i] - '0';
		}
	}
	sort(a + 1, a + j + 1,cmp);
	for(i = 1;i < j;i++){
		if((i == 1 && a[i] == 0 )||(i != 1) && !f) continue;
		else{
			cout << a[i];
			f = 1;
		}
	}
	if(!f) cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}