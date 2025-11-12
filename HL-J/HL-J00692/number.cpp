#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	
	int len=s.size();

	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[cnt++]=s[i]-'0';
		
		}
}
	sort(a,a+cnt);
	for(int i=cnt-1;i<=cnt;i--){
		cout<<a[i];
		if(i==0) break;
	}
	return 0;
}