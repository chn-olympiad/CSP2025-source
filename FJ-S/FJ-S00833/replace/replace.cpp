#include<bits/stdc++.h>
using namespace std;

int n,q;
string str[105],str2[105],a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>str[i]>>str2[i];
	} 
	while(q--){
		cin>>a>>b;
		int cnt=0;
		for(int i=0;i<n;i++){
			if(str[i]==a && str2[i]==b){
				cnt++;
			}
		}
		cout<<cnt<<endl; 
	}
	return 0;
}
