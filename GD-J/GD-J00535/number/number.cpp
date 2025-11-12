#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	string x,s="";
	int lenofs=0;
	cin>>x;
	for(int i=0;i<x.size();i++)if(x[i]>='0' and x[i]<='9')s+=x[i],lenofs++;
	for(char i='9';i>='0';i--){
		for(int j=0;j<lenofs;j++){
			if(s[j]==i)cout<<i;
		}
	}
	return 0;
} 
