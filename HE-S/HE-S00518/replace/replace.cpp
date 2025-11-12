#include<bits/stdc++.h>
using namespace std;
string c[100001][2];
int n,q,ans;
bool dg(string a,string b){
	if(a==b) return 1;
	for(int i=0;i<a.size();i++){
		string a1=" ";
		for(int j=i;j<=a.size();j++){
			a1==c[j][0];
			for(int l=1;l<=n;l++){
				if(c[l][0]==a1){
					string ls=a;
					for(int e=i;e<=j;e++){
						ls[e]=c[l][1][e-i];
						if(dg(ls,b))ans++;
					}
				}
			}
		}
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>c[i][0]>>c[i][1];
	}
	string b[2];
	while(q--){
		ans=0;
		cin>>b[0]>>b[1];
		dg(b[0],b[1]);
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
