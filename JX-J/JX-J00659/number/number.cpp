#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[s.size()+5],b=0;
    for(int i=0;i<s.size();i++){
	     if(s[i]=='1'){
			 a[i]=1;
			 b+=1;
	     }
	     if(s[i]=='2'){
			 a[i]=2;
			 b+=1;
		 }
		 if(s[i]=='3'){
			 a[i]=3;
			 b+=1;
		 }
		 if(s[i]=='4'){
			 a[i]=4;
			 b+=1;
		 }
		 if(s[i]=='5'){
			 a[i]=5;
			 b+=1;
		 }
		 if(s[i]=='6'){
		     a[i]=6;
		     b+=1;
		 }
		 if(s[i]=='7'){
			 a[i]=7;
			 b+=1;
		 }
		 if(s[i]=='8'){
			 a[i]=8;
			 b+=1;
	     }
	     if(s[i]=='9'){
			 a[i]=9;
			 b+=1;
		 }
		 if(s[i]=='0'){
			 a[i]=0;
			 b+=1;
		 }	
    }
    sort(a,a+b-1);
    for(int i=b-1;i>0;i++){
		cout<<a[i];
	}
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
