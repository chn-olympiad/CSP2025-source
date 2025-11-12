#include<bits/stdc++.h> 
using namespace std;
string s;
char data[1000010];
int l=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			data[l++]=s[i];
		}
	}
	sort(data,data+l);
	while(l--){
		printf("%c",data[l]); 
	}
	return 0;
}
