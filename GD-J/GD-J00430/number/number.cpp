#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define N 1000005
using namespace std;
int a[N];
ll cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	string s;
	cin>>s;
	int n = s.size();
	for(int i = 0 ; i < n; i++){
		if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9'){
			a[++cnt] = (s[i]-'0');
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i = 1; i <= cnt; i++){
		cout<<a[i];
	}
	return 0;
} 
