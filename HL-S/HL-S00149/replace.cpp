#include<bits/stdc++.h>
using namespace std;
int a[124567];
int ans=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int yuyuyu=1;
	for(int i = yuyuyu;i<=n;i++){
		for(int j=yuyuyu;j<=m;j++){
			if(a[i]=='65'||a[i+1]=='66'){
				ans++;
			}else{
				break;	
			}
		}
		cout<<ans<<endl;
	}
	for(int i = 2;i<n;i++){
		cout<<"0"<<endl;
	}
	return 0;
}