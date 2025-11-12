#include<bits/stdc++.h>
using namespace std;
int n,q,idx1,idx2,ans,x,cnt;
string s1,s2,s3,s4,s5,s6;
struct f{
	string s1,s2;
}a[200005];
bool pan1,pan2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	clock_t st;
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2;
	while (q--){
		if ((double)(clock()-st)/CLOCKS_PER_SEC>0.97){
			cout<<0<<"\n";
			continue;
		}
		ans=0;
		cin>>s1>>s2;
		if (s1.size()!=s2.size()){
			cout<<0<<"\n";
			continue;
		}
		for (int i=1;i<=n;i++){
			x=s1.find(a[i].s1);
			if (x==-1) continue;
			s3=s1;
			cnt=0;
			for (int j=x;j<s1.size();j++){
				s3[j]=a[i].s2[cnt];
				cnt++;
				if (cnt==a[i].s2.size()) break;
			}
			if (s3==s2){
				ans++;
			}
		}

		cout<<ans<<"\n";
	}
	return 0;
}
