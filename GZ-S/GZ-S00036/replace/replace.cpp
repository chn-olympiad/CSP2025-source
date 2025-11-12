//GZ-S00036 六盘水市第二十四中学 冉哲睿
#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200001],s2[200001],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>t1>>t2;
		int l1,ans=0;
		for(int i=1;i<=n;i++){
			if(s1[i]==t1||s2[i]==t2){
				if(s1[i]==t1&&s2[i]==t2)ans++;
				continue;
			}
			int w=-1,l=s1[i].size();
			while(w=t1.find(s1[i],w+1)){
				string s=t1;
				for(int j=0;j<l;j++){
					s[j+w]=s2[i][j];
				}
				if(s==t2)ans++;
				if(w==-1)break;
			}if(w==-1)continue;
		}cout<<ans<<endl;
	}
	return 0;
}

