#include<bits/stdc++.h>
using namespace std;
int n=0;
int s[105];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	if(n>=3){
		if(s[1]+s[2]>s[3]&&s[2]+s[3]>s[1]&&s[1]+s[3]>s[2]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
} 
