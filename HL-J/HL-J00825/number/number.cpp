#include<bits/stdc++.h>

using namespace std;
const int N=1e6+10;

string s;
int a[N];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int l1=s.length();
	int l2=0;
	for(int i=0;i<l1;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[l2]=s[i]-'0';
			l2++;
		}
	}
	sort(a,a+l2);
	for(int i=l2-1;i>=0;i--){
		cout << a[i];
	}
	return 0;
}