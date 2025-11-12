#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N],q1,q2;
int main(){
freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		int ans=0;
		cin>>q1>>q2;
		for(int i=0;i<n;i++){
			int k=0,f1=0,f2=0;
			for(int j=0;j<q1.size();j++){
				if(q1[j]==s1[i][k]){
					f1=1;
					for(int k;k<s1[i].size();k++){
						if(q1[j+k]!=s1[i][k]){
							f1=0;
							break;
						}
					}
				}
				for(int j=0;j<q2.size();j++){
				if(q2[j]==s2[i][k]){
					f2=1;
					for(int k;k<s2[i].size();k++){
						if(q2[j+k]!=s2[i][k]){
							f2=0;
							break;
						}
					}

				}
			}if(f1==1&&f2==1&&q1.size()==q2.size()){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
