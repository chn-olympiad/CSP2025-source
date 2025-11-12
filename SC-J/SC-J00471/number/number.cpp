#include <bits/stdc++.h>
using namespace std;
string str;
unsigned int a[1000010],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0' && str[i]<='9'){
			a[++cnt]=str[i]-'0';
		}
		
	}
	sort(a+1,a+1+cnt);
	bool b=1;
	for(int i=cnt;i>=1;i--){
		if(b==1 && a[i]==0 && i>1){
			continue;
		}
		cout<<a[i];
		b=0;
	}
	return 0;
}