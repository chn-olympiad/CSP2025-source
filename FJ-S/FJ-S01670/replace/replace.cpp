#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[10000],b[10000],c[10000],d[10000];
unordered_map<string,string> w;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		w[a[i]]=b[i];
		w[b[i]]=a[i];
	}
	for(int i=1;i<=q;i++){
		cin>>c[i]>>d[i];
		cout<<0<<endl;
//		string s="";
//		for(int j=0;j<c[i].size();j++){
//			for(int k=j;k<c[i].size();k++){
//				s="";
//				for(int z=j;z<=k;z++){
//					s+=c[i][z];
//					if(w[])
//				}
//			}
//		}
	}
	return 0;
}


