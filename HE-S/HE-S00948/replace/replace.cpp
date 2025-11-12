#include <bits/stdc++.h>
using namespace std;
int n,q,ans;
string a[200005],b[200005],q1,q2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		ans=0;
		cin>>q1>>q2;
		for(int i=0;i<n;i++){
			if(q1.find(a[i])==-1) continue;
			string z="";
			for(int j=0;j<q1.find(a[i]);j++){
				z=z+q1[j];
			}
			for(int j=0;j<b[i].size();j++){
				z=z+b[i][j];
			}
			for(int j=q1.find(a[i])+a[i].size();j<q1.size();j++){
				z=z+q1[j];
			}
			if(z==q2) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
