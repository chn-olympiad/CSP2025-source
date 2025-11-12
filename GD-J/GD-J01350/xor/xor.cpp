#include<bits/stdc++.h>
using namespace std;
int n,ln,yi;
long long k;
long long a[500005];
bool fg=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) fg=false;
		if(a[i]==1){
			yi++;
			if(a[(i%2==0?i+1:i-1)]==a[i]){
				ln++;
			}
		}
		if(a[i]==0) ln++;
	}if(fg==true){
		cout<<n/2<<endl;
		return 0;
	}
	if(k==1){
		cout<<yi<<endl;
	}else if(k==0){
		cout<<ln<<endl;
	}else{
		int l=0,ans=0;
		for(int i=2;i<=n;i++){
			if(a[i]==k){
				l=0;
				ans++;
				continue;
			}
			if(l==0) l=a[i];
			else l^=a[i];
			if(l==k){
				ans++;
				l=0;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
