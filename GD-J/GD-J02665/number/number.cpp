#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char ch[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ch;
	int n=strlen(ch);
	sort(ch,ch+n);
	reverse(ch,ch+n);
	int tag=0;
	for(int i=0;i<n;i++){
		if(ch[i]>='0'&&ch[i]<='9'){
			cout<<ch[i];
			if(tag==0&&ch[i]=='0')return 0;
			if(tag==0)tag=1;
		}
	}
	return 0;
}
