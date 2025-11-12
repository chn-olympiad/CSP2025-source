#include<bits/stdc++.h>
using namespace std;
string s;
long long x[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0,len=s.size();i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int num=s[i]-'0';
			x[num]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(x[i]>0){
			printf("%d",i);
			x[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
