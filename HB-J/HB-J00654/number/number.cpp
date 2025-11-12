#include<bits/stdc++.h>
using namespace std;
int num;
string s;
char a[1000005];
bool cmp(char a,char b){
	return a>b;
}
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   cin>>s;
   for(int i=0;i<s.length();i++){
	   if(s[i]>='0'&&s[i]<='9'){
		   a[num]=s[i];
		   num++;
	   }
   }
	sort(a,a+num,cmp);	   
    for(int i=0;i<=num;i++){
		cout<<a[i];
	}
   return 0;
}
