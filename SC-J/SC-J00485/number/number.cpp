#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
string S;
int n,cnt,a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>S;
	n = S.size();
	cnt = 0;
	for(int i = 0;i<n;i++){
		if(S[i]>='0'&&S[i]<='9'){
			cnt++;
			a[cnt] = S[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i = cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}