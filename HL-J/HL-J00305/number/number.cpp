#include<bits/stdc++.h>
using namespace std;
char s[1000000];
char maxn[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=strlen(s);
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]>maxn[i]){
				maxn[i]=s[i];
			}
			}
		}
	cout<<maxn;
	return 0;
}
