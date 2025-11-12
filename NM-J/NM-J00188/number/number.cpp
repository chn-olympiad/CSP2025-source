#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);

string s;
string p;
int sum=0;
cin>>s;
for(int i=0;i<s.size();i++){
    if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='6'||s[i]=='5'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){

        p[sum]=s[i];
        sum++;
    }
}
int n=sum;
 int a[n];
for(int i=0;i<n;i++){

       a[i]=p[i];

}
for(int i=0;i<n;i++){
   for(int j=0;j<n-1;j++){
   if(a[j]<a[j+1]){
        swap(a[j],a[j+1]);
    }
}
}
for(int i=0;i<n;i++){
  if(a[i]==48){
  	cout<<0;
  }
  else if(a[i]==49){
  	cout<<1;
  }

 else if(a[i]==50){
  	cout<<2;
  }
 else if(a[i]==51){
  	cout<<3;
  }
 else if(a[i]==52){
  	cout<<4;
  }
 else if(a[i]==53){
  	cout<<5;
  }
 else if(a[i]==54){
  	cout<<6;
  }
 else if(a[i]==55){
  	cout<<7;
  }
else if(a[i]==56){
  	cout<<8;
  }
 else if(a[i]==57){
 	cout<<9;
  }
}



return 0;
}
