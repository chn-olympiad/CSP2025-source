#include<bits/stdc++.h>
using namespace std;
int n,r,a[1101101],cnt,sum,ans,v[5101][5101];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int l=1;l<=n;l++){
		sum=0;
		for(int i=l;i<=n;i++){
	    	for(int j=i;j<=n;j++){
		    	cnt=a[i];
		    	for(int k=i+1;k<=j;k++){
			    	cnt=cnt^a[k];
			    }
			    if(cnt==r && !v[i][j]){
			    	sum++;
			    	v[i][j]=1;
				    i=j;
				    break;
		    	}
		    }
	    }
	    ans=max(ans,sum);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
