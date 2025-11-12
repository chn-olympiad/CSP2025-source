#include<bits/stdc++.h>
using namespace std;
int n,a[200005],f,ff,k,ans=0,fff,h,h1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
		if(i!=1&&a[i]!=a[i-1]) fff=1;
		if(a[i]>1) ff=1;
	}
	//cout<<f<<' '<<ff<<' '<<fff<<' '<<k<<endl;
	if(f==0&&k==0&&ff==0&fff==0) cout<<n/2;
	else if(f==0&&k==1&&ff==0&&fff==0) cout<<n;
	else if(f==1&&ff==0&&k==1&&fff==0) cout<<0;
	else if(f==1&&ff==0&&k==0&&fff==0) cout<<n;
	else if(k==0&&ff==0&&f==1&&fff==1){
		for(int i=1;i<=n;){
			if(a[i]==a[i+1]) ans+=1,i=i+2;
			else {
				h=0;
				h1=0;
				for(int j=i;j<=n;j++){
					if(a[j]==1) h+=1;
					else h1+=1;
					if(h1>1){
						ans+=2;
						i+=j+1;
						break;
					}
					if(h%2==0){
						ans++;
						i+=j+1;
						break;
					}
				}
			}
		}
		cout<<ans;
	}
	else if(k==1&&ff==0&&f==1&&fff==1){
		for(int i=1;i<=n;){
			if(a[i]!=a[i+1]) ans+=1,i=i+2;
			else {
				h=0;
				h1=0;
				for(int j=i;j<=n;j++){
					if(a[j]==0) h+=1;
					else h1+=1;
					if(h1>1){
						ans+=2;
						i+=j+1;
						break;
					}
					if(h%2==0){
						ans++;
						i+=j+1;
						break;
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}