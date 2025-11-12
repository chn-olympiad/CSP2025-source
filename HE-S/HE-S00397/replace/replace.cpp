#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200010];
string s2[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int st1=t1.size();
		int st2=t2.size();
		if(st1!=st2){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<st1;i++){
			for(int j=i+1;j<st1;j++){
				for(int k=1;k<=n;k++){
					if(t1.substr(i,j-i+1)==s1[k]&&t2.substr(i,j-i+1)==s2[k]){
						if(t1.substr(0,i)==t2.substr(0,i)&&t1.substr(j+1,st1-j)==t2.substr(j+1,st1-j)){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
