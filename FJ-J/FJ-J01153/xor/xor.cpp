#include <bits/stdc++.h>
using namespace std;
int a,b,c[500001],ans,d,maxn,minn=10000000000,v[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
		maxn=max(maxn,c[i]);
		minn=min(minn,c[i]);
	}
	if(maxn==minn&&minn==1){
		cout<<a/2;
		return 0;
	}
	if(maxn==1){
		if(b==1){
			for(int i=1;i<=a;i++){
				ans+=c[i];
			}
		}
		else{
			for(int i=1;i<=a;i++){
				if(c[i]==1&&c[i+1]==1){
					ans++;
				}
				if(c[i]==0){
					ans++;; 
				}
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=a;i++){
		if(c[i]==b){
			ans++;
			v[i]=1;
		}
	}
	for(int i=1;i<=a;i++){
		bool y=0;
		for(int j=i;j<=a;j++){
			int x=0;
			for(int k=i;k<=j;k++){
				if(v[k]==1){
					y=1;
					break;
				}
				x^=c[k];
			}
			if(y==1){
				break;
			}
			if(x==b){
				for(int k=i;k<=j;k++){
					v[k]=1;
				}
				ans++;
			}
		}
		if(y==1){
			continue;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
