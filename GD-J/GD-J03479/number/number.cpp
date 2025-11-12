#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=100;
ll cnt[N];
string st;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>st;
	for(int i=0;i<st.size();i++) 
		if('0'<=st[i]&&st[i]<='9') cnt[st[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(cnt[i]--) cout<<i;
	return 0;
}
/*
//freopen
//freopen
froepen
freoepn
#include<bits\stdc++.h> 
x0 y0 x1 y1
signed main() 
*/
