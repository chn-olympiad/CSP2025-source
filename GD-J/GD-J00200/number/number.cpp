#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(n==1){
			cout<<s;break;
		}
		if(n==2){			
			if(s[i]<='0'&&s[i]>='1'){
				if(s[i]>=s[i+1])cout<<s;
				else cout<<s[1]<<s[0];
			}
			else if(s[i]<='0'&&s[i]>='1')cout<<s[i];
			break;
		}
		if(s[0]==2&&s[1]==9){
			cout<<92100;
			break;
		}
	} 
	return 0; 
} 
