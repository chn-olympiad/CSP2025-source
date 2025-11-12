#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200010],b[200010],c[200010],d[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<q;i++){
		cin>>c[i]>>d[i];
		if(c[i].size()!=d[i].size()){
			cout<<0<<"\n";
		}else{
			int s=0;
			for(int j=0;j<c[i].size();j++){
				for(int k=j;k<c[i].size();k++){
					string q="";
					for(int w=j;w<=k;w++){
						q+=c[i][w];
					}
					for(int w=0;w<n;w++){
						if(a[w]==q){
							string r="";
							for(int p=0;p<k;p++){
								r+=c[i][p];
							}
							for(int p=0;p<q.size();p++){
								r+=c[i][p];
							}
							for(int p=k+1;p<=c[i].size();p++){
								r+=c[i][p];
							}
							if(r==d[w]){
								s++;
							}
						}
					}
				}
			}
			cout<<s<<"\n";
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
