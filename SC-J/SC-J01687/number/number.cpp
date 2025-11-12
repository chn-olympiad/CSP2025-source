#include<bits/stdc++.h> 
using namespace std;
string st,num;
int main(){
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  cin>>st;
  for(int i=9;i>=0;i--){
  	for(int j=0;j<st.size();j++){
  	    if(st[j]==char(i+'0')){
  	    	num=num+char(i+'0');
  	    	st[j]='A';
		}
  	}
  }
  cout<<num;
  return 0;
}