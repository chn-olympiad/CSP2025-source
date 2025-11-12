#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[5000005],b[5000005];
int b1[500005],b2[500005];
string q1,q2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size();j++){
			if(a[i][j]=='b'){
				b1[i]=i;
				break;
			}
		}
		for(int j=0;j<a[i].size();j++){
			if(b[i][j]=='b'){
				b2[i]=i;
				break;
			}
		}
	}
	while(q--){
		cin>>q1>>q2;
		if(q1.size()!=q2.size()){
			cout<<0<<endl;
			continue;
		}
		int k1=0,k2=0,ans=0;
		for(int i=0;i<q1.size();i++){
			if(q1[i]=='b')k1=i;
			if(q2[i]=='b')k2=i;
		}
		for(int i=1;i<=n;i++){
			if(abs(k2-k1)==abs(b1[i]-b2[i])&&min(k1,k2)>=min(b1[i],b2[i])){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}