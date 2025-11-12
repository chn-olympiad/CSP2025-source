#include<bits/stdc++.h>
using namespace std;
int c[123];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int f=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]!='0'){
				f=1;
			}
			if(s[i]=='0'){
				c[0]+=1;
			}
			if(s[i]=='1'){
				c[1]+=1;
			}
			if(s[i]=='2'){
				c[2]+=1;
			}
			if(s[i]=='3'){
				c[3]+=1;
			}
			if(s[i]=='4'){
				c[4]+=1;
			}
			if(s[i]=='5'){
				c[5]+=1;
			}
			if(s[i]=='6'){
				c[6]+=1;
			}
			if(s[i]=='7'){
				c[7]+=1;
			}
			if(s[i]=='8'){
				c[8]+=1;
			}
			if(s[i]=='9'){
				c[9]+=1;
			}
		}
	}
	if(!f){
		cout<<f;
	}
	for(int i=9;i>=0;i--){
		while(c[i]!=0){
			cout<<i;
			c[i]--;
		}
	}
	return 0;
}
