#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,q;
pair< string , string > a[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=1;i<=n;i++){
		string s_1,s_2;
		cin>>s_1>>s_2;
		a[i].first=s_1,a[i].second=s_2; 
	}
	while(q--){
		long long ans=0;
		string y,z;
		cin>>y>>z;
		for(long long i=1;i<=n;i++){
			string h=a[i].first;
			string e=a[i].second;
			if(y.size()<h.size()) continue;
			for(long long j=0;j<y.size();j++){
				if(y[j]==h[0]){ 
					bool flag=false;
					long long g=0;
					for(long long k=0;k<h.size();k++,j++,g++){
						if(h[k]!=y[j]){
							flag=true;
							break;
						}
					}
					if(flag==false){
						string u=y;
						for(long long l=j-g,o=0;l<j;l++,o++) u[l]=e[o];
						if(u==z) ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
