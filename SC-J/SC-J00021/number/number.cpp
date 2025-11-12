#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int a[N],index=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[index]=(int)(s[i]-'0');
			index++;
		}
	}
	sort(a,a+index);
	for(int i=index-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
