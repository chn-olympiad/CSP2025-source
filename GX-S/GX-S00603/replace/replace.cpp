#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	long long ans=0;
	while(q--){
		cin>>t1>>t2;
		ans=0;
		int l1=t1.size(),l2=t2.size();
		if(l1!=l2){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<l1;i++){
			if(i!=0){
				if(t1[i-1]!=t2[i-1])break;
			}
			for(int j=1;j<=n;j++){
				int n1=s1[j].size();
				int flag=1;
				if(i+n1>l1)continue;
				for(int z=0;z<n1;z++){
					if(s1[j][z]!=t1[i+z]){
						
						flag=0;
						break;
					} 
					if(s2[j][z]!=t2[z+i]){
						flag=0;
						break;
					}
					
				}
				if(flag==0)continue;
				for(int z=i+n1;z<l1;z++){
					if(t1[z]!=t2[z]){
						flag=0;
						break;
					}
				}
				ans+=flag;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
