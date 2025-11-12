#include<bits/stdc++.h>

using namespace std;

string a[100005];
string b[100005];

signed main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	int n,q;
	cin>>n>>q;
	
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	
	for(int i=0;i<q;i++){
		string c2,d;
		cin>>c2>>d;
		int ans=0;
		for(int j=0;j<n;j++){
			int v=0;
			string c;
			while((v=c2.find(a[j],v))!=-1){
				c=c2;
				if(c.replace(v,b[j].size(),b[j])==d){
					//cout<<c.replace(v,b[j].size(),b[j])<<";"<<d<<";"<<j<<endl;
					ans++;
				}
				v++;
			}
		}
		cout<<ans<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

