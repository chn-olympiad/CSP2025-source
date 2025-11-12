#include<bits/stdc++.h>
using namespace std;
#define int long long
string ak[230000],bk[230000];
vector<string> ap[5000005],au[5000005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>ak[i]>>bk[i];
		ap[ak[i].size()].push_back(ak[i]);
		au[ak[i].size()].push_back(bk[i]);
	}
	while(m--){
		string a,b;
		cin>>a>>b;
		int l=-1,r=-1;
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i]){
				if(l==-1){
					l=i;
				}
				r=i;
			}
		}
		int ans=0;
		for(int i=0;i<=l;i++){
			string now="",nowp="";
			for(int j=i;j<r;j++){
				now+=a[j],nowp+=b[j];
			}
			for(int j=r;j<b.size();j++){
				now+=a[j],nowp+=b[j];
			//	cout<<"--"<<now<<" "<<nowp<<endl;
				for(int z=0;z<ap[j-i+1].size();z++){
					if(ap[j-i+1][z]==now&&au[j-i+1][z]==nowp){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//T1 60 T2 奇怪的时间复杂度，0~30吧（不要制裁我！）  
