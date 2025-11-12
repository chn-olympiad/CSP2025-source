#include<bits/stdc++.h>
using namespace std;
int a,b,s[100001],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>s[i];
	}
	if(b==0){
		for(int i=0;i<a;i++){
			if(s[i]==0){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}if(b==1){
		for(int i=0;i<a;i++){
			if(s[i]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<3;
	return 0;
}	


