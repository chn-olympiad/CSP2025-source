#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q,l1,l2,lt,ans,l[200001];
	string t1,t2,s1[200001],s2[200001];
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		l[i]=s1[i].length();
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>t1>>t2;
		lt=t1.length();
		for(int j=1;j<=n;j++){
			l1=t1.find(s1[j]);
			l2=t2.find(s2[j]);
			if((t1.substr(0,l1)==t2.substr(0,l2))&&(t1.substr(l1+l[j],lt-l1-l[j])==t2.substr(l2+l[j],lt-l2-l[j]))){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
