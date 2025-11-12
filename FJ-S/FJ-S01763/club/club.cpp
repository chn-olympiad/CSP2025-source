#include<bits/stdc++.h>
using namespace std;
long long t,m=0,cnt;
int a[3][100000];
int n[5];
int ans[5];
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
		cin>>t;
		for(long long i=1;i<=t;i++){
			cin>>n[i];
			for(long long j=m;j<m+n[i];j++){
				for(int k=0;k<3;k++){
					cin>>a[k][j];
					}
				}
				if(n[i]==2){
					for(int c=0;c<3;c++){
						for(int b=0;b<3;b++){
							if(b!=c){
							cnt=a[c][m]+a[b][m+1];
							if(cnt>ans[i]) ans[i]=cnt;}
						}
					}
				}
				if(n[i]==4){
					for(int c=0;c<3;c++){
						for(int b=0;b<3;b++){
							for(int d=0;d<3;d++){
							for(int f=0;f<3;f++){
							if(c==b&&b==d&&d==f||c==b&&b==d||c==b&&b==f||c==d&&d==f||b==d&&d==f) break;
							else{
							cnt=a[c][m]+a[b][m+1]+a[d][m+2]+a[f][m+3];
							if(cnt>ans[i]) ans[i]=cnt;
							}}}
						}
					}
				}
			m+=n[i];
			cout<<ans[i]<<endl;
		}
		return 0;
		}
		
	
