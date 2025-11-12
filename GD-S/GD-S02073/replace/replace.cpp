#include<bits/stdc++.h>
using namespace std;
string a[200005],b[200007],ta,tb;
int l,r,s=0,ans=0,n,q;
int main(){
	ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		cin>>ta>>tb;
		s=0;
		ans=0;
		for(int i=0;i<ta.size();i++){
			if((i==0||ta[i-1]==tb[i-1])&&ta[i]!=tb[i]){
				s++;
				l=i;
			}
			if((i+1==ta.size()||ta[i+1]==tb[i+1])&&ta[i]!=tb[i]){
				r=i;
			}
		}
		for(int i=1;i<=n;i++){
			long long fa=ta.find(a[i]),fb=tb.find(b[i]);
			if(fa<ta.size()&&fa==fb&&fa+a[i].size()>=r&&fb<=l&&r-l+1<=a[i].size()){
				ans++;
				//cout<<ta<<" "<<tb<<" "<<a[i]<<" "<<b[i]<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
