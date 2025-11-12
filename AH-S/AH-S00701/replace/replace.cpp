#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
map <string,int> mp;
vector <string> lt[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	//cout<<mp["123"];
	//memset(v,127,sizeof(v));
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		if(mp[a]){
			lt[mp[a]].push_back(b);
		}
		else{
			mp[a]=i;
			lt[i].push_back(b);
		}
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		int l,r=a.size(),ans=0;
		int f=0;
		for(int j=0;j<a.size();j++){
			if(a[j]!=b[j]){
				if(f==0){
					f=1;
					l=j;
				}
				else if(f==2){
					f=-1;
					break;
				}
			}
			if(a[j]==b[j]){
				if(f==1){
					r=j;
					f=2;
				}
			}
		}
		if(f==-1){
			cout<<"0\n";
			continue;
		}
		for(int p=0;p<=l;p++){
			for(int q=r;q<=a.size();q++){
				if(mp[a.substr(p,q)]){
					for(int j=0;j<lt[mp[a.substr(p,q)]].size();j++){
						if(b.substr(p,q)==lt[mp[a.substr(p,q)]][j]) ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
