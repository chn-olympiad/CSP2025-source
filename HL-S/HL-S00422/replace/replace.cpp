#include<bits/stdc++.h>
using namespace std;

bool pt(string a,string b,int c){
	for(int i=c;i<b.length()+c;i++){
		if(a[i]!=b[i-c]){
			return false;
		}
	}
	return true;
}
string a[300000]={},b[300000]={};
string x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	while(m--){
		cin>>x>>y;
		int s=0;
		if(x.length()!=y.length()){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<x.length();i++){
			for(int j=0;j<n;j++){
				if(x[i]==a[j][0] &&pt(x,a[j],i)){
					string h="";
					int l=0;
					for(int k=0;k<x.length();k++){
						if(l<=a[j].length()&& i<=k){
							h+=b[j];
							l+=a[j].length()+1;
							k+=a[j].length()-1;
							continue;
						}
						h+=x[k];
					}
					if(h==y){
						s++;
					}
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
} 
