#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct replace{
	string f;
	string t;
	int difs;int dife;
	int fh;int th;
};
vector<replace> rp;
int hasher(string s,int h,int e){
	int ha=0;
	for(int i=h;i<e;i++){
		ha+=s[i]<<(i-h)%32;
	}
	return ha;
}
int main(){
	int n,q;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string a,b;
		cin>>a>>b;
		int difs=-1,dife=-1;bool indiff=false;
		for(int j=0;j<a.size();j++){
			if(a[j]!=b[j]){
				if(difs==-1){
					difs=j;
					indiff=true;
				}else if(dife!=-1)indiff=true;
			}else if(indiff){
				dife=j;
				indiff=false;
			}
		}
		if(indiff)dife=a.size();
		rp.push_back({a,b,difs,dife,hasher(a,difs,dife),hasher(b,difs,dife)});
	}
	for(int i=0;i<q;i++){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<"0"<<endl;
			continue;
		}
		int difs=-1,dife=-1;bool indiff=false;
		for(int j=0;j<a.size();j++){
			if(a[j]!=b[j]){
				if(difs==-1){
					difs=j;
					indiff=true;
				}else if(dife!=-1)indiff=true;
			}else if(indiff){
				dife=j;
				indiff=false;
			}
		}
		if(indiff)dife=a.size();
		int ahash=hasher(a,difs,dife);
		int bhash=hasher(b,difs,dife);
		int ans=0;
		for(auto j:rp){
			if(difs<j.difs||j.f.size()+difs-j.difs<dife||j.f.size()+difs-j.difs>a.size())continue;
			if(ahash!=j.fh||bhash!=j.th)continue;
			bool ok=true;
			for(int k=difs-j.difs;k<j.f.size()+difs-j.difs;k++){
				if(a[k]!=j.f[k-difs+j.difs]){
					ok=false;
					break;
				}
			}
			if(ok)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
