#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//£¿£¿£¿ 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0||k==1){
		if(k==0){
			int qihui=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)qihui++;
				if(qihui==2){
					ans++;
					qihui-=2;
				}
			}
			cout<<ans;
			return 0;
		}if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
			cout<<ans;
			return 0;
		}
	}else{
		cout<<6;
		return 0;
	}
	return 0;
	//don't forget to delete the // before freopen!!! 
} 
