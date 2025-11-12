#include<bits/stdc++.h>
using namespace std;
string a[200005],b[200005],ta,tb;
string subsub(string ap,int pos,int n){
	string v;
	v.clear();
	long long cnt=0;
	for(int i=pos;;i++){
		v=v+string(1,ap[i]);
		cnt++;
		if(cnt==n){break;}
	}
	return v;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		cin>>ta>>tb;
		if(ta.size()!=tb.size()){
			cout<<"0\n";
			continue;
		}
		long long ans=0;
		for(int i=0;i<n;i++){
			if(a[i].size()<=ta.size()){
			for(int j=0;j<=ta.size()-a[i].size();j++){
				if(subsub(ta,j,a[i].size())==a[i]){
					string pot=ta;
					for(int ip=j;ip<j+a[i].size();ip++){
						pot[ip]=b[i][ip-j];
					}
					if(pot==tb){
						ans++;
					}
				}
			}
		}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
