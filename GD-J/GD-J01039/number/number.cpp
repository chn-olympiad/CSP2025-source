#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
string s1;
int c=0,a[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]=='1'||s1[i]=='2'||s1[i]=='3'||s1[i]=='4'||s1[i]=='5'||s1[i]=='6'||s1[i]=='7'||s1[i]=='8'||s1[i]=='9'||s1[i]=='0'){
			a[c]=s1[i]-'0';
			c++; 
		}
	}
	sort(a,a+c,cmp);
	for(int i=0;i<c;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
