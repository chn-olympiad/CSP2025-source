#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
string a[200001][2];
string b[200001][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>b[i][0]>>b[i][1];
		int ans=0;
		for(int k=1;k<=n;k++){
			for(int j=0;b[i][0][j]!='\0';j++){
				int l=0;
				int lj=j;
				while(b[i][0][j]==a[k][0][l]&&b[i][0][j]!='\0'){
					l++;
					j++;
				}
				bool sc=0;
				if(a[k][0][l]=='\0'){
					l=0;
					for(int s=lj;s<j;s++){
						if(b[i][1][s]!=a[k][1][l]){
							sc=0;
							break;
						}
					}
					if(sc==0) ans++;
				}
			}
		}
		printf("%d",ans);
	}
	return 0;
}
