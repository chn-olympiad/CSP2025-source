#include<bits/stdc++.h>
using namespace std;
string s;
int l;
struct aa{
	int sz;
	int gs;
}a[15];
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	
	for(int i=0;i<l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			cnt=s[i]-'0';
			a[cnt].sz=cnt;
			a[cnt].gs++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i].gs;j++){
			cout<<a[i].sz;
		}
	}
	return 0;
}
