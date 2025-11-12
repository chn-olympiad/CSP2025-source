#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],j;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin); freopen("number.out","w",stdout); 
   cin>>s;

  	  for(int i=0;i<s.size();++i){
    	if(s[i]>='0'&&s[i]<='9'){
    	   a[j]=s[i]-48;
    	   j++;
		}
	}

  
	sort(a,a+j,cmp);
	for(int i=0;i<j;++i) printf("%d",a[i]);
	fclose(stdin); fclose(stdout);
	return 0;
}