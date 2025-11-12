#include<bits/stdc++.h>
using namespace std;
string hs[200009],sh[200009];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	ios::sync_with_stdio(0);
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++)cin>>hs[i]>>sh[i];
	for(int i=1;i<=b;i++){
		string x,y;
		cin>>x>>y;
		int ans=0;
		for(int j=1;j<=a;j++){
			string tx="";
			for(int k=0;k+hs[j].length()-1<x.length();k++){
				int fl=1;
				for(int l=0;l<hs[j].length();l++){
					if(x[k+l]!=hs[j][l]){
						fl=0;
						break;
					}
				}
				if(fl==1){
					string fx=tx+sh[j];
					for(int l=k+hs[j].length();l<x.length();l++)fx+=x[l];
					if(fx==y){
						ans++;
						break;
					}
				}
				tx+=x[k];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
