#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e6+5;
string s;
int num[maxn],tot;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			num[++tot]=s[i]-'0';
		}
	}
	sort(num+1,num+tot+1);
	for(int i=tot;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}
