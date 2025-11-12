#include<bits/stdc++.h>
#define int long long
using namespace std;
struct h{
	string a,b;
};
int n,k;
vector<h >v; 
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}
	while(k--){
		string a,b,e;
		cin>>a>>b;
		e=a;
		int res=0;
		for(int i=0;i<n;i++){
			if(a.size()>=v[i].a.size()){
				bool q;
				for(int j=0;j<a.size()-v[i].a.size()+1;j++){
					q=1;
					for(int t=0;t<v[i].a.size();t++){
						if(v[i].a[t]!=a[j+t]){
							q=0;
							break;
						}
					}
					if(q){
						for(int t=0;t<v[i].b.size();t++){
							a[t+j]=v[i].b[t];
						}
						if(a==b)res++;
						a=e;
						break;
					}
				}
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}
