#include<bits/stdc++.h>
using namespace std;
int n,q;
char s[1011][2025],s1[1011][2025];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		scanf("%s %s",s[i]+1,s1[i]+1);
	}
	while(q--){
		char t[114514],t1[114514];
		scanf("%s %s",t+1,t1+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=strlen(t+1)-strlen(s[i]);j++){
				bool flag=true;
				for(int k=1;k<j;k++){
					if(t[k]!=t1[k]){
						flag=false;
						break;
					}
				}
				for(int k=j+strlen(s[i]+1);k<=strlen(t+1);k++){
					if(t[k]!=t1[k]){
//						cout<<i<<' '<<j<<' '<<k<<endl;
						flag=false;
						break;
					}
				}
				if(!flag){
					continue;
				}
				for(int k=1;k<=strlen(s[i]+1);k++){
					if(s[i][k]!=t[j+k-1]||s1[i][k]!=t1[j+k-1]){
//						cout<<i<<' '<<j<<' '<<k<<endl;
						flag=false;
						break;
					}
				} 
				if(flag){
//					cout<<i<<' '<<j<< endl;
					ans++;
				}
			} 
		}
		cout<<ans<< endl;
	}
}
