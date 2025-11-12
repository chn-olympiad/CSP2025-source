#include<bits/stdc++.h>
using namespace std;
long long n,q;
string s1[200010],s2[200010],t,jie;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	getline(cin,t);
	for(long long i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(long long i=1;i<=q;i++){
		cin>>t>>jie;
		long long ans=0,sss=t.size();
		for(long long ss=1;ss<=n;ss++){
			for(long long j=0;j<sss;j++){
				if(t.substr(j,s1[ss].size())==s1[ss]){
					string t1=t.substr(0,j),t2=t.substr(j+s1[ss].size(),sss-1);
					string t3=t1+s2[ss]+t2;
					if(t3==jie)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
