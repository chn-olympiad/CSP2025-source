#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1[20005],s2[20005];
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int i=0;
		int ans=0;
		while(t1[i]!='\0'){
			for(int j=1;j<=n;j++){
				bool flag=1;
				int f=0;
				if(t1.length()-i>=s1[j].length()){
					if(t1[i]==s1[j][0]&&t2[i]==s2[j][0]){
						while(t1[i+f]!='\0'&&s1[j][f]!='\0'){
							if(t1[f+i]!=s1[j][f]&&t2[i+f]!=s2[j][f]){
								flag=0;
								break;
							}
							f++;
						}
						while(t1[i+f]!='\0'){
							if(t1[i+f]!=t2[i+f]){
								flag=0;
							} 
							f++;
						}
						if(flag){
							ans++;
						}
					}
				}
			}
			if(t1[i]!=t2[i]){
				break;
			}
			i++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
