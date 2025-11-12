#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	
	long long int n,q;
	cin>>n>>q;
	string s1[n+3],s2[n+3],t1[q+3],t2[q+3];
	for(int i=0;i<n;i++){
		
		cin>>s1[i]>>s2[i];
	
	}	
	for(int i=0;i<q;i++){
		int ans=0;
		cin>>t1[i]>>t2[i];
		for(int j=0;j<t1[i].size();j++){
			
			if(t1[i][j]!=t2[i][j]){
				
				for(int k=0;k<n;k++){
					string op="";
					if(s1[k].size()<t1[i].size()-j&&s1[k][0]==t1[i][j]){
						
						for(int l=j;l<s1[k].size()+j;l++){
							
							op+=t1[i][l];
						}
						
						
						if(s1[k]==op){
							int b=0;
							for(int j1=j+s1[i].size();j1<t1[i].size();j1++){
								
								if(t1[i][j]!=t2[i][j]){
									b=1;
									break;
								}
							}
							if(b==0){
								ans++;
								
							}
						}
					}
					else{
						for(int j2=j;j2>=0;j2--){
							if(s1[k].size()<t1[i].size()-j2&&s1[k][0]==t1[i][j2]){
								for(int l=j2;l<s1[k].size()+j2;l++){
							
							op+=t1[i][l];
						}
						
						
						if(s1[k]==op){
							int b=0;
							for(int j1=j2+s1[i].size();j1<t1[i].size();j1++){
								
								if(t1[i][j2]!=t2[i][j2]){
									b=1;
									break;
								}
							}
							if(b==0){
								ans++;
								
							}
						}
							}
						}
					}
				}
			break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
