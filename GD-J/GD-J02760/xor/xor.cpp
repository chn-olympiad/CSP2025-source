#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005][50],b[500005],x,p,s,ww;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		p=0;
		while(x!=0)a[i][p++]=x%2,x/=2;
		b[i]=p;
		if(i!=0){
			for(int j=0;j<max(b[i],b[i-1]);j++){
				if(a[i][j]==a[i-1][j])a[i][j]=0;
				else a[i][j]=1;
			}
			b[i]=max(b[i],b[i-1]);
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=i-1;j>=ww;j--){
			int t=0;
			for(int u=max(b[i],b[j])-1;u>=0;u--){
				if(a[i][u]==a[j][u])t=t*2;
				else t=t*2+1;
			}
			if(t==k){
				s++;
				ww=i;
				break;
			}
		}
	}
	cout<<s;
	return 0;
} 


