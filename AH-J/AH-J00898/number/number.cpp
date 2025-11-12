#include <bits/stdc++.h>
using namespace std;
int num[1000010],tot=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int lens=s.size();
	for(int i=0; i<lens; i++){
		if(s[i]>='0' && s[i]<='9'){
			num[tot]=s[i]-'0';
			tot++;
		}	
	}
	sort(num,num+tot);
	for(int i=tot-1; i>=0; i--) printf("%d",num[i]);
	return 0;
}
