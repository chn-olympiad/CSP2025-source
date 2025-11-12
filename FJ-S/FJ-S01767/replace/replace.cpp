#include<bits/stdc++.h>
using namespace std;
int n,q,s;
string a[101],b[101];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		s=0;
		string tx,ty;
		cin>>tx>>ty;
		int ll=0,rr=tx.size()-1;
		for(int i=0;i<tx.size();i++){
			if(tx[i]!=ty[i]){
				ll=i;
				break;
			}
		}
		for(int i=tx.size()-1;i>=0;i--){
			if(tx[i]!=ty[i]){
				rr=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i].size()>=rr-ll+1){
				for(int j=max(int(rr+1-a[i].size()),int(0));j<=ll;j++){
					bool f=1;
					if(j+a[i].size()>tx.size())
						break;
					for(int k=j;k<j+a[i].size();k++){
						if(tx[k]!=a[i][k-j]||ty[k]!=b[i][k-j]){
							f=0;
							break;
						}
					}
					if(f){
						s++;
					}
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}  
