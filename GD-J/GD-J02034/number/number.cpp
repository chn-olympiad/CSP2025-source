#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int b){
	return x>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
int p=0;
 
	string s;
	cin>>s;
char a[1005];
	for(int i=0;i<=s.size();i++){
		if(s[i]=='0'||s[i]=='9'||s[i]=='8'||s[i]=='7'||s[i]=='6'||s[i]=='5'||s[i]=='4'||s[i]=='3'||s[i]=='2'||s[i]=='1'||s[i]=='0'){
          	a[p]=s[i]+'\0';
		p++;
		}
	}
sort(a,a+p,cmp);
 //sort(a+1,a+sum+1,cmp);
for(int i=0;i<p;i++){
	cout<<a[i];
}
 
} 
