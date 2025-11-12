#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int t[11],sum;
string x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]=='0'){
				t[0]++;
				sum++;
			}else if(s[i]=='1'){
				t[1]++;
				sum++;
			}else if(s[i]=='2'){
				t[2]++;
				sum++;
			}else if(s[i]=='3'){
				t[3]++;
				sum++;
			}else if(s[i]=='4'){
				t[4]++;
				sum++;
			}else if(s[i]=='5'){
				t[5]++;
				sum++;
			}else if(s[i]=='6'){
				t[6]++;
				sum++;
			}else if(s[i]=='7'){
				t[7]++;
				sum++;
			}else if(s[i]=='8'){
				t[8]++;
				sum++;
			}else{
				t[9]++;
				sum++;
			}
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<t[i];j++){
			if(i==9) x+='9';
			else if(i==8) x+='8';
			else if(i==7) x+='7';
			else if(i==6) x+='6';
			else if(i==5) x+='5';
			else if(i==4) x+='4';
			else if(i==3) x+='3';
			else if(i==2) x+='2';
			else if(i==1) x+='1';
			else if(i==0) x+='0';
		}
	}
	cout<<x;
	return 0;
}
