#include<bits/stdc++.h>
using namespace std;
int a[105510][105510];
int main(){
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
	int n,t;
	int ans;
	cin>>t;
	while(t--){
		ans=0;
		memset(a,0,sizeof(a));
		cin>>n;
		int dd=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int k=1;k<=pow(3,n);k++){
			ans=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=n;j++){
					ans+=a[i][j];
				}
			}
			if(ans>dd){
				dd=ans;
			}
		}
		cout<<dd<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
