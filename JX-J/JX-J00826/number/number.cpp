#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
bool cmp(int a, int b){
    return a > b;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin>>s;
	int num = 0;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
				a[num] = s[i] - '0';
				num++;
		}
	}
	sort(a, a + num, cmp);
	for(int i = 0;i < num;i++){
		cout<<a[i];
	}
	return 0;
}
