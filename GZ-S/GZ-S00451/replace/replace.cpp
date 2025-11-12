//GZ-S00451 贵州师范大学云岩实验中学 闫峻浩
#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[10005],s2[10005],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		long long ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			int fi=t1.find(s1[i]);
			if(fi==-1) continue;
			else{
				string tnow=t1;
				for(int j=fi;j<fi+s1[i].size();j++){
					tnow[j]=s2[i][j-fi];
				}
				if(tnow==t2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
