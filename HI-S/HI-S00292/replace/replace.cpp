#include<bits/stdc++.h>
using namespace std;
int n,q;
struct pp{
	string ll1,ll2;
}a[200005];
string s,s1,ss;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a[i].ll1>>a[i].ll2;
	}
	while(q--){
		cin>>s>>s1;
		int ans=0;
		for(int i=1;i<=n;i++){
			ss=s;
			int k=s.find(a[i].ll1);
			while(k!=-1){
				ss=s;
				if(k!=-1){
					ss.erase(k,a[i].ll1.size());
					ss.insert(k,a[i].ll2);
					if(ss==s1) ans++;
				}
				k=s.find(a[i].ll1,k+1);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

