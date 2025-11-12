#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k,ans=0;
	cin>>n>>k;
	bool spea=1,speb=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(k==0&&spea==1)
			if(a[i]!=1) spea=0;
		if((k==0 || k==1) && speb==1)
			if(a[i]!=1 && a[i]!=0) speb=0;
	}
	
	
	//特殊性质a
	if(k==0&&spea==1) ans=n/2; 
	
	//特殊性质b
	else if(k==0&& speb==1){
		ans=0;
		for(int i=2;i<=n;){
			if(a[i]==a[i-1]){
				ans++;
				i+=2;
			}
			else if(a[i]==0 && a[i-1]==1 && a[i+1]==1){
				ans++;
				i+=3;
			}
			else i++;
		}
	}
	else if(k==1 && speb==1){
		for(int i=2;i<=n;){
			if(a[i]!=a[i-1]){
				ans++;
				i+=2;
			}
			else if(a[i]==1&&a[i-1]==1&&a[i+1]==1){
				ans++;
				i+=3;
			}
			else i++;
		}
	}
	
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
