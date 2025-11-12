#include<bits/stdc++.h>
using namespace std;
int s[500024];
int cmp(int ans,int w){
	int p[1024],q[1024],i=1,j=1,sum=0;
	while(ans>0){
		p[i]=ans%2;
		ans/=2;
		i++;
	}
	while(w>0){
		q[j]=w%2;
		w/=2;
		j++;
	}
	for(int k=max(i,j);k>=1;k--){
		if(p[k]==q[k]){
			p[k]=0;
		}else{
			p[k]=1;
		}
	}
    for(int k=max(i,j),u=0;k>=1;k--){
		sum+=p[k]*pow(2,u);
		u++;
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,a,ans,maxn=0,i,j,k;
    cin>>n>>a;
    for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			ans=0;
			for(k=i;k<=j;k++){
				if(k==i){
					ans+=s[k];
				}else{
					ans=cmp(ans,s[k]);
				}
			}
			if(ans==a){
				maxn++;
				break;
			}
		}
        if(i==n || j==n){
			break;
		}
	}
	cout<<maxn<<endl;			
	fclose(stdin);
	fclose(stdout);
      
    return 0;
}

