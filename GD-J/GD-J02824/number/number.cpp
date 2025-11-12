#include<bits/stdc++.h>
using namespace std;
int nb[1000005];
int cnt;
string s; 
void hh(){
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' and s[i]<='9'){
			nb[cnt++]=s[i]-'0';
		}
	}
	sort(nb,nb+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<nb[i];
	}
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	hh();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
