#include<bits/stdc++.h>
using namespace std;


bool cmp(int x ,int y)
{
	return x > y;
}

const int N = 1e6 + 5;
string s;
int a[N];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	cin >> s;
	int j = 1;
//	bool f = 0;
	for(int i = 0;i <= s.size() - 1;++ i){
//		f = 0;
		if(s[i] >= '0' && s[i] <= '9'){
			a[j] = s[i] - '0';
			j ++;
//			f = 1;
		}
	}
//	cout << j << '\n';
	j --;
//	cout << j;
	sort(a + 1,a + j + 1,cmp);
	for(int i = 1;i <= j;++ i){
		cout << a[i];
	}
	return 0;
}
