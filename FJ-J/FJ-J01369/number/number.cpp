#include<bits/stdc++.h>
using namespace std;
string s;
int arrn[1005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=0;
	int i=0;
	int a=0;
	while(s[i]!='\0'){
		if(s[i]>='0'&&s[i]<='9'){
			arrn[a]=s[i];
			len++;
			a++;
		}
		i++;
	}
	sort(arrn,arrn+len);
	for(int j=len-1;j>=0;j--){
		cout<<(char)arrn[j];
	}
	return 0;
}
