#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
string a[200010],b[200010];
map<string,int> m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		m[a[i]]=i;
	}
	for( ;q--; ){
		string u,v;
		ll ans=0;
		cin>>u>>v;
		int len=u.size();
		for(int i=0;i<len;i++)
			for(int j=i;j<len;j++){
				string cnt="",u2=u;
				for(int k=i;k<=j;k++)
					cnt+=u[k];
				if(m[cnt]!=0){
					for(int k=i;k<=j;k++)
						u2[k]=b[m[cnt]][k-i];
					if(u2==v) ++ans;
				}
			}
		printf("%lld\n",ans); 
	}
}
