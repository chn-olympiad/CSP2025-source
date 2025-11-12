#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s[n],s1[n];
	for(int i=0;i<n;i++){
		cin>>s[i]>>s1[i];
	}
	string sq[q],sq1[q];
	for(int i=0;i<q;i++){
		cin>>sq[i]>>sq1[i];
	}
	for(int i=0;i<q;i++){
		bool b=0;
		for(int j=0;j<n;j++){
			if(sq[i]==s[j]&&sq1[i]==s1[j]){
				int num=0;
				for(int i=0;i<s[i].size();i++){
					if(s[i]!=s1[i]){
						num++;
					}
				}
				if(num==s[i].size()){
					cout<<1<<endl;
				}
				else if(num>=2){
					cout<<2<<endl;
				}
				else{
					int l=0;
					for(int i=s[i].size();i>0;i--){
						l+=i;
					}
					cout<<l<<endl;
				}
				b=1;
			}
		}
		if(b==0){
			cout<<0<<endl;
		}
	}
	return 0;
} 