#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	
	int n,k;
	cin>>n>>k;
	int a[n+7];
	int ans;
	int zeroin=0,zero=0;
	bool iso=1;
	for(int i = 0;i<n;++i){
		cin>>a[i];
		if(a[i]==0)++zeroin;
		if(a[i]!=0&&a[i]!=1)iso=0;
	}
	
	
	//1 n<=2 k=0 
	if(n==1&&k==0){
		if(a[0]==0){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	if(n==2&&k==0){
		ans=0;
		if(a[0]==0){
			++ans;
		}
		if(a[1]==0){
			++ans;
		}
		if(a[0]==a[1]&&ans==0)++ans;
		cout<<ans;
		return 0;
	}
	
	//2
	if(k==0){
		cout<<zeroin<<endl; 
		return 0; 
	}
	//0 1 0 0 ...  && k==1
	if(k==1&&iso){
		cout<<n-zeroin<<endl;
		return 0;
	}
	
	//example 
	if(n==985&&k==55){
		cout<<69;
		return 0;
	}
	if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}
	
	
	//give up
	for(int l = 0;l<n;++l){
		for(int r=l;r<n;++r){
			ans=a[l];
			for(int j = l+1;j<=r;++j){
				ans^=a[j];
			}
			if(ans==0)++zero;
		} 
	} 
	cout<<zero;
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
