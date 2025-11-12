#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100][100],b[100],m,ans,num,op;
bool f[100],ch=0,lr=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
	    cin>>m; op=0;
	    if(m==1) num++;
	    if(m!=0&&m!=1) lr=1;
	    while(m){
	    	op++;
	    	if(m%2==1) b[op]++;
	    	m=m/2;
	    	ans=max(op,ans);
		}
		for(int j=ans;j>=1;j--){
			a[i][j]=a[i-1][j]+b[j];
			b[j]=0;
		}
	}
	op=0;
	if(!lr){
		if(k==0) cout<<n;
		else if(k==1) cout<<num;
		return 0;
	}
	num=0;
    while(k){
	    op++;
	    if(k%2==1) b[op]++;
	    k=k/2;
	}
	for(int j=op;j>=1;j--){
		if(b[j]) f[j]=1;
		b[j]=0;
	}
	op=1; 
	for(int i=1;i<=n;i++){
		for(int j=op;j<=i;j++){
			ch=1;
			for(int z=1;z<=ans;z++){
			    if(((a[i][z]-a[j-1][z])%2==0)&&f[z]){
			    	ch=0;
			    	break;
				}	
				else if(((a[i][z]-a[j-1][z])%2==1)&&!f[z]){
					ch=0;
					break;
				}
			}
			if(ch) num++,op=i+1;
			if(op==i+1) break;
		}
	}
	cout<<num;
	return 0;
}
