#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	 
	 string s;
	 cin>>s;	
	 vector<int> a;
	 for(int i=0;i<s.size();i++){
	 	char c=s[i];
	 	if(c>='0'&&c<='9')
		 {	 	 
	 	a.push_back(c-'0'); 
		 }
	 }
	 sort(a.begin(),a.end(),cmp) ;
	 if(a[0]!=0){	 
	 for(int i=0;i<a.size();i++){
	 	cout<<a[i];
	 }
	 	 }
	 	 else{
	 	 	cout<<0; 
		  }
	return 0;
	
} 
