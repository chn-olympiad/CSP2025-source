#include<bits/stdc++.h>
using namespace std;
int n,q;
string aa[100000][2];
string a,b;
bool ans[100000];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>aa[i][1]>>aa[i][2];
		ans[i]=1;
		}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		for(int j=1;j<=int(a.length());j++)
			{
			if (a[j]==b[j]){
				continue;
				}	
			else{
				for(int y=1;y<=n;y++)
					for(int w=1;w<=int(aa[n][1].length());w++){
						if(aa[n][2][w]==b[j+w-1]){
							continue;
							}
						else{
							ans[j]=0;
							
							}
						}
						if(ans[j]==0) break;
						}
				}
			
			}
		
	for(int m=1;m<=q;m++){
		cout<<ans[m]<<' ';
	}
	return 0;
	}
		
		
			
