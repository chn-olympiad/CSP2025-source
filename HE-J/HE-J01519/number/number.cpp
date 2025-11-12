#include<bits/stdc++.h>
using namespace std;
string s;
int b[1000001];
int tmp=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[tmp]=(s[i]-'0');
			tmp++;
		}
	}
	sort(b,b+tmp);
	for(int i=tmp-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
