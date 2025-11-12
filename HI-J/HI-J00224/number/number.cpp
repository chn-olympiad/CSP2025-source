#include<bits/stdc++.h>
using namespace std;
string in;
int cnt[10];
//abs(a)<abs(o)
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	getline(cin,in);
	int len=in.length();
	for(int i=0;i<len;i++){
		if('0'<=in[i]&&in[i]<='9'){
			cnt[in[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++)printf("%d",i);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

