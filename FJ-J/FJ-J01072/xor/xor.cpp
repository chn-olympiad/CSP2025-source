#include<bits/stdc++.h>
using namespace std;
int a[500050];
bool c[500050];
int n,k,ans;
int sa(){
	return n/2;
}
int sb(){
	int tmp=0;
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(a[i-1]==1&&c[i-1]!=1){
					c[i-1]=1;
					c[i]=1;
					tmp++;
				}else if(a[i+1]==1&&c[i+1]!=1){
					c[i+1]=1;
					c[i]=1;
					tmp++;
				}
			}
		}
	}
	return tmp;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	int m=0,mi=INT_MAX;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(a[i],m);
		mi=min(a[i],mi);
	} 
	if(m==1){
		if(mi==1){
			sa();
		}else{
			sb();
		}	
	}else{
		for(int i=1;i<=n;i++){
			int l=i;
			if(c[i]==1)continue;
			if(a[i]==k){
				ans++;
				c[i]=1;
				continue;
			}
			int tmp=a[i];
			int r=l+1;
			while(r<=n){
				tmp=tmp^a[r];
				if(tmp==k){
					ans++;
					for(int j=l;j<=r;j++){
						c[j]=1;
					}
				}
				r++;
			}
		}
		cout<<ans;
	}
	return 0;
} 

