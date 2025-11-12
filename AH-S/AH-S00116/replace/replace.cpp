#include<bits/stdc++.h>
using namespace std;
string x[200005],y[200005];
int n,q,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	int qq=q;
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		ans=0;
		if(n<=100&&qq<=100){
			for(int i=1;i<=n;i++){
				int len=t1.size()-x[i].size()+1;
				for(int j=0;j<len;j++){
					string s2=t1.substr(j,x[i].size());
					if(s2==x[i]){
						string s3=t1.substr(0,j)+y[i]+t1.substr(j+x[i].size(),t1.size()-j);
						if(s3==t2)ans++;
					}
				}
			}
		}
		else{
			int len=t1.size();
			for(int i=1;i<=n;i++){
				int j=t1.find(x[i]);
				if(j<len){
					string s3=t1.substr(0,j)+y[i]+t1.substr(j+x[i].size(),len-j);
					if(s3==t2)ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
