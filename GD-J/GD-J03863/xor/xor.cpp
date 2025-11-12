#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flagen=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flagen=0;
	}
	if(flagen){
		if(k)
			cout<<n;
		else
			cout<<n/2;
		return 0;
	}if(!k){
		for(int i=1;i<=n;i++){
			if(!a[i]) ans++;
			else if(a[i]==a[i+1]){
				ans++;
				i++;
			} 
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]) ans++;
			else if(a[i]==a[i+1]){
				ans++;
				i++;
			} 
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

