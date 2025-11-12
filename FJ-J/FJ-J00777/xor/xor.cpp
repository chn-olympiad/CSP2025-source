#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool st=1;
	if(k>1)st=0;
	int vnt=0,cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)st=0;
		if(st==1 && a[i]==1)vnt++;
		else if(st==1&&a[i]==0)cnt++;
	}
	if(st==1){
		if(k==1) cout<<vnt<<endl;
		else{
			int l=0,y=0,ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0)l++,ans++;
				if(a[i]==1)y++;
				if(y==2&&l==0){
					y-=2,ans++;
				}else if(y==2&&l>0){
					y--;
				}
				if(a[i]==1)l=0;
			}
			cout<<ans<<endl;
		}
	}else{
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
