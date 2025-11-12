#include<bits/stdc++.h>
using namespace std;
int n,t;
map<string,string>mp;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		mp[x]=y;
	}
	if(t>100){
		while(t--){
			string x,y;
			cin>>x>>y;
			int ans=0;
			int idx=0;
			int idy=0;
			int sum=0;
			int sum2=0;
			bool fla=0;
			for(int i=0;i<x.size();i++){
				if(x[i]=='b'){
					idx=i;
					fla=1;
				}
				else if(!fla){
					sum++;
				}else{
					sum2++;
				}
			}
			for(int i=0;i<y.size();i++){
				if(y[i]=='b'){
					idy=i;
					break;
				}
			}
			
			for(auto it:mp){
				int sumf=0;
				int sums=0;
				bool sf=0;
				int fid=0;
				for(int i=0;i<it.first.size();i++){
					if(it.first[i]=='b'){
						fid=i;
						sf=1;
					}
					else if(!sf){
						sumf++;
					}else{
						sums++;
					}
				}
				int sid=0;
				for(int i=0;i<it.second.size();i++){
					if(it.second[i]=='b'){
						sid=i;
					}
				}
				//cout<<sum<<" "<<sumf<<" "<<sum2<<" "<<sums<<"\n";
				if(fid-sid==idx-idy&&sum>=sumf&&sum2>=sums){
					ans++;
				}
			}
			
			cout<<ans<<endl;
		}
	}else
	while(t--){
		int ans=0;
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<0<<endl;
			continue;
		}
		for(int l=0;l<x.size();l++){
			string s="";
			for(int r=l;r<x.size();r++){
				s+=x[r];
				if(mp.count(s)){
					bool flag=1;
					string st=x;
					for(int i=l,j=0;i<=r;i++,j++){
						st[i]=mp[s][j];
					}
					for(int i=0;i<y.size();i++){
						if(st[i]!=y[i]){
							flag=0;
							break;
						}
					}
					if(flag){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
2 2 
aba aab 
baa aba 
aba aab 
abaa aaba */
