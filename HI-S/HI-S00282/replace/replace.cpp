#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	char s[n][2]={};
	char t[q][2]={};
	for(int i = 0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i = 0;i<q;i++){
		cin>>s[i][0]>>t[i][1];
		if(abs(t[i][0]-t[i][1])>100){
			cout<<q<<endl;
		}
		else{
			cout<<0;
		}
	}
	
	return 0;
} 
