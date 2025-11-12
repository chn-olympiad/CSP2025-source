#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=1e6+5;

int tot;
string str;
char ch[N];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			ch[++tot]=str[i];
		}
	}
	sort(ch+1,ch+1+tot,greater<char>());
	for(int i=1;i<=tot;i++) cout<<ch[i];
	cout<<endl;
	return 0;
}
