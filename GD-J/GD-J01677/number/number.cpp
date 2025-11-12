#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
   int a[20];
   for(int j=0;j<20;j++){
   	a[j]=0;
   }
  string s;
  cin>>s;
  //if(s[2]=='a') cout<<"a";
 // cout<<s.size();
   for(int i=0;i<s.size();i++){
   	if(s[i]=='0'){
   		a[0]++;
	   }
   	else if(s[i]=='1'){
   		a[1]++;
	   }
	else if(s[i]=='2'){
		a[2]++;
	}
	else if(s[i]=='3'){
		a[3]++;
	}
	else if(s[i]=='4'){
		a[4]++;
	}
	else if(s[i]=='5'){
		a[5]++;
	}
	else if(s[i]=='6'){
		a[6]++;
	}
	else if(s[i]=='7'){
		a[7]++;
	}
	else if(s[i]=='8'){
		a[8]++;
	}
	else if(s[i]=='9'){
		a[9]++;
	}
   }
   for(int n=9;n>=0;n--){
   	for(int m=1;m<=a[n];m++) cout<<n;
   }
}
