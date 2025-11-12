#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l = s.size();
	for(int i = 0;i<l;i++)
		if(s[i] >= '0' && s[i] <= '9')
			a[s[i] - '0']++;
	for(int i = N;i>=0;i--){
		while(a[i]>0){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
