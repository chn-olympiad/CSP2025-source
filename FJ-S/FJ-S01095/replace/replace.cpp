#include<bits/stdc++.h>
using namespace std;
int n,q;
struct zfcz{
	string s1,s2;
};
zfcz s[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;

	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	
	while(q--){
		string zc1,zc2;
		string str1,str2;
		cin>>str1>>str2;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(s[i].s1==str1&&s[i].s2==str2){
				sum++;
			}
			}
			for(int j=0;j<str1.size();j++){
					if(str1[j]!=str2[j]){
						zc1+=str1[j];
						zc2+=str2[j];
					}
				}
		for(int i=1;i<=n;i++){
				if(zc1==s[i].s1&&zc2==s[i].s2){
					sum++;
				}
			}
			cout<<sum<<endl;
		}
		
	
	
	
	
	
	
	
	
	return 0;
}
