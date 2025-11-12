#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a[n],b[n],al,bl;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int w=0;w<q;w++){
		cin>>al>>bl;int l=0,r=0;
		for(int i=0;i<n;i++){
			
			bool qwe=false;
			for(int j=0;j<al.size();j++){
				bool tru=true;
				for(int t=j;t<min(j+a[i].size(),al.size());t++){
					if(a[i][t-j]!=al[i]){
						tru=false;
						break;
					}
				}
				if(tru){
					qwe=true;
					l++;
					break;
				}
			}
			
		}
		for(int i=0;i<n;i++){
			
			bool qwe=false;
			for(int j=0;j<bl.size();j++){
				bool tru=true;
				for(int t=j;t<min(j+b[i].size(),bl.size());t++){
					if(b[i][t-j]!=bl[i]){
						tru=false;
						break;
					}
				}
				if(tru){
					qwe=true;
					r++;
					break;
				}
			}
			
		}cout<<min(r,l)<<endl;
	}
	return 0;
}
