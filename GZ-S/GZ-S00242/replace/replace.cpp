//GZ-S00242	贵阳市第三实验中学	李金泽 
#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
map<int,string>s1;
map<int,string>s2;
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<ans<<endl;
		}else{
			for(int j=1;j<=n;j++){
				int a=t1.find(s1[j]);
				int b=t2.find(s2[j]);
				if(a==b && a!=-1 && b!=-1){
					int l=t1.size();
					bool mark=1;
					for(int k=0;k<a;k++){
						if(t1[k]!=t2[k]){
							mark=0;
							break;
						}
					}
					for(int k=a+s1[j].size();k<l;k++){
						if(t1[k]!=t2[k] or mark==0){
							mark=0;
							break;
						}
					}
					if(mark==1)ans++;
				}
			}
			cout<<ans<<endl;
			ans=0;
		}
	}
	return 0;
}
