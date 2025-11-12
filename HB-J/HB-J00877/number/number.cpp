#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int sl=s.length();
	int num[sl]={0};
	int nl=0;
	for(int i=0;i<=sl;i++){
		if(s[i]>='0' && s[i]<='9'){
			num[nl]=s[i];
			nl+=1;
		}
	}
	sort(num,num+nl);
	for(int i=nl-1;i>=0;i--){
			cout<<num[i]-48;
		}
	return 0;
}
