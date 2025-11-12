#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,q;
string s1[N],s2[N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		cin>>t1>>t2;
		int l=-1,r=0,l1=t1.size(),l2=t2.size();
		if(l1!=l2){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<l1;i++){
			if(l==-1&&t1[i]!=t2[i])l=i;
			if(t1[i]!=t2[i])r=i;
		}//cout<<l<<' '<<r<<'\n';
		int ans=0;
		for(int i=1;i<=n;i++){
			int j=0,len=s1[i].size();
			if(r-l+1>len)continue;
			if(len>l1)continue;
			while(1){
				j=t1.find(s1[i],j);
				//cout<<j<<'\n';
				if(j==-1)break;
				if(l<j)break;
				if(j+len<=r){j++;continue;}
				bool flag=1;
				for(int k=j;k<j+len;k++){
					//cout<<t2[k]<<s2[i][k-j]<<'\n';
					if(t2[k]!=s2[i][k-j]){
						flag=0;
						break;
					}
				}
				if(flag)ans++;
				j++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

