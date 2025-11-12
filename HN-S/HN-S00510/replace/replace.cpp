#include<bits/stdc++.h>
using namespace std;
int n,q,l,r,pos,ans;
string S1[200010],S2[200010],L1,L2;
int main(){
	//冷静下来  我相信你 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>S1[i]>>S2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>L1>>L2;
		if(L1.size()!=L2.size()){
			cout<<0<<"\n";
			continue;
		}
		ans=0,l=0,r=0;
		for(int i=0;i<=L1.size()-1;i++){
			if(L1[i]!=L2[i]){
				if(l==0)l=i;
				r=i;
			}
		}
		if(l==0){
			cout<<0<<"\n";
			continue;
		}
		for(int j=1;j<=n;j++){
			if(S1[j].size()<(r-l+1))continue;
			pos=0;
			while(1){
				pos=L1.find(S1[j],pos);
				if(pos>l||pos<0)break;
				if(pos+L1.size()-1<r)continue;
				string C=L1.substr(0,pos)+S2[j]+L1.substr(pos+S1[j].size(),L1.size()-pos-S1[j].size());
				if(C==L2)ans++;
				pos++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
