#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cnt=0,g[15];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
for(int i=0;i<s.size();i++){
	if(s[i]>='0'&&s[i]<='9'){
		++g[int(s[i]-'0')];
	}
}
for(int i=9;i>=0;i--){
	for(int j=1;j<=g[i];j++){
		printf("%d",i);
	}
}

fclose(stdin);
fclose(stdout); 
return 0;
}
