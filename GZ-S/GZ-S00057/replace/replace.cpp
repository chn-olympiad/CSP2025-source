//GZ-S00057 毕节七星关东辰实验学校 刘杰 
#include<bits/stdc++.h>
using namespace std;
string cp[200001],cp1[200001];
int fid(string a,string b){
	int c=b.size();
	for(int i=0;i+c<a.size();i++){
		bool ok=0;
		for(int j=i,k=0;j<i+c;j++,k++){
			if(a[j]!=b[k]){
				ok=1;break;
			}
		}
		if(!ok){
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>cp[i]>>cp1[i];
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;int ans=0;
		for(int k=1;k<=n;k++){
			//baoli
			//gets 30 pts!
			string o;
			int c=fid(a,cp[k]);//cout<<c<<endl;
			if(c!=-1){
				for(int j=0;j<c;j++){
					o+=a[j];
				} 
				o+=cp1[k];
				for(int j=c+cp1[k].size();j<a.size();j++){
					o+=a[j];
				}
				//cout<<o<<endl;
				if(o==b){
					ans++;
				}
			}
			else if(a==cp[k]){
				if(cp1[k]==b){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
