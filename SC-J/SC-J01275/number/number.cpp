#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int b[N];
int cnt;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if((s[i]>='0')&&(s[i]<='9')){
			b[cnt]=s[i];
			cnt++;
		}
	}
	sort(b,b+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<b[i]-48;
	}
	return 0;
} 