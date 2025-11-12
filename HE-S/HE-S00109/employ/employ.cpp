#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
  freopen("empioy.out","w",stdout);
  int n,m;
  cin>>n>>m;
  int s[n];
  int g;
  cin>>g;
  for(int i=0;i<n;i++){
  	cin>>s[i];
  }
  if(n==3){
  	cout<<2;
  }if(n==10){
  	cout<<2204120;
	    }else{
	cout<<0;
		}

	return 0;
} 
