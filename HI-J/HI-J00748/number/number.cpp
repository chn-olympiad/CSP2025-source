#include<bits/stdc++.h>
using namespace std;
string nin="",eie="",sev="",six="",fiv="",fou="",thr="",two="",one="",zer="";
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","W",stdout);
 string s; cin>>s;
 string ss="";
 for(int i=0;i<s.size();i++){
 	if(s[i]<='9'&&s[i]>='0'){
	  ss=ss+s[i];
   }
}
   for(int i=0;i<ss.size();i++){
   	  if(ss[i]=='9') nin=nin+ss[i];
   	  if(ss[i]=='8') eie=eie+ss[i];
   	  if(ss[i]=='7') sev=sev+ss[i];
   	  if(ss[i]=='6') six=six+ss[i];
   	  if(ss[i]=='5') fiv=fiv+ss[i];
   	  if(ss[i]=='4') fou=fou+ss[i];
   	  if(ss[i]=='3') thr=thr+ss[i];
   	  if(ss[i]=='2') two=two+ss[i];
   	  if(ss[i]=='1') one=one+ss[i];
   	  if(ss[i]=='0') zer=zer+ss[i];
   }
   cout<<nin+eie+sev+six+fiv+fou+thr+two+one+zer;
	return 0;
}
