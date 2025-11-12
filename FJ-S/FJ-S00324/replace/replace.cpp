#include<bits/stdc++.h>
using namespace std;

int n,q;

string s1,s2;

map<int,string>a[1000005];
int main(){
	
	freopen("replace.in","r",stdin);
	 freopen("replace.out","w",stdout);
	  cin>>n>>q;
	  for(int i=0;i<=n;i++){
	  	cin>>a[i][1]>>a[i][2];
	  while(q--){
	  	cin>>s1>>s2;
	  	if(s1.size()!=s2.size()){
	  		cout<<0<<endl;
	  		continue;
		  }
		  /*for (int i=0;i<=n;i++){
		  	if (a[i][1].size>s1.size()){
		  		continue;
			  }
			  */
			  cout<<0<<endl;
	          cout<<0<<endl;
		  } 
	    }
	  } 
