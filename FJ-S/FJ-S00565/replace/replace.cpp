#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,q;
struct node{
	string ft,sd;
};
node s[200005],t[200005];
bool exc(string tx,string sx,string ty,string sy){
	if(sx.size()>tx.size()) return false;
	if(sy.size()>ty.size()) return false;
	int j=0;
	for(int i=0;i<tx.size();i++){
		if(tx[i]==sx[j]){
			j++;
			if(j==sx.size()){
				for(int k=i-j+1,l=0;l<sy.size();k++,l++){
					tx[k]=sy[l];
				}
				break;
			}
		} 
		else j=0;
	}
	if(tx==ty) return true;
	else return false;
}
int main(){
	freopen("relpace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].ft>>s[i].sd;
	}
	for(int i=1;i<=q;i++){
		long long ans=0;
		cin>>t[i].ft>>t[i].sd;
		for(int j=1;j<=n;j++){
			if(exc(t[i].ft,s[j].ft,t[i].sd,s[j].sd)) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
