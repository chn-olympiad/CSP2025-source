#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010],cnt = 1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i <= s.size()-1;i++){
		s[i] -= '0';
		if(s[i] >= 0 && s[i] <= 10){
			a[cnt] = s[i];
			cnt++;
		}
	}
	sort(a,a+cnt+1);
	for(int i = cnt-1;i >= 1;i--){
		cout<<a[i];
	}
	return 0;
}
