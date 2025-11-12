#include<bits/stdc++.h>
using namespace std;
string a[20001000][3];
int an1s[200001000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int ans=0;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=m;++i){
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int j=1;j<=n;++j){
			
			if(a[j][1]==t1){
				if(a[j][2]==t2){
				ans++;
				}
				string c="";
				int id;
				for(int k=0;k<a[j][1].size();++k){
					if(a[j][1][k]!=t2[k]){
						id=k;
						c+=t2[k];
					}
				}
				if(t2.size()!=a[j][2].size()){
					an1s[i]=0;
					break;
				}
				for(int k=id-c.size()+1;k<a[j][2].size();++k){
					if(a[j][2][k]==c[0]){
						bool cs=true;
						//cout<<1;
						for(int o=k;o<k+c.size();++o){
							
						//	cout<<2;
							//cout<<a[j][2][o]<<' '<<k-o+1<<endl;
							if(a[j][2][o]!=c[o-k]){
								//cout<<a[j][2][o]<<"     "<<k-o<<' '<<c[k-o]; 
								cs=false;
							}
						}
						//cout<<cs;
						if(cs==true){
							ans++;
						}
					}
				}
				//cout<<c<<endl;
			}
		}
		an1s[i]=ans;
	}
	for(int i=1;i<=m;++i){
		cout<<an1s[i]<<endl;
	}
	return 0;
}
