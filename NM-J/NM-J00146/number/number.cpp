#include<bits/stdc++.h>
using namespace std;

string s;
char c[1000005];
int num=0;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			num++;
			c[num]=s[i];
		}
	}
	sort(c+1,c+1+num,cmp);
	for(int i=1;i<=num;i++){
		if(c[1]==0){
			cout<<0;
			return 0;
		}
		cout<<c[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
