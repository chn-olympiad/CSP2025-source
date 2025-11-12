#include<bits/stdc++.h>
using namespace std;
string s;
long long s1[1000010],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	for(int i = 0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			s1[cnt] = int(s[i]-'0');
		}
	}
	sort(s1+1,s1+cnt+1);
	for(int i = cnt;i>=1;i--){
		cout <<s1[i];
	}
	return 0;
}

