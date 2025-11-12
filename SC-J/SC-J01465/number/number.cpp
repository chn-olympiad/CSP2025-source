#include <bits/stdc++.h>
using namespace std;
string s;
char so[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			so[j]=s[i];
			j++;
		}
	}
	sort(so,so+j);
	for(int i=j-1;i>=0;i--){
		cout<<so[i];
	}
	return 0;
}