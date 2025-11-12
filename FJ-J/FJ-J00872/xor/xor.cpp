#include <bits/stdc++.h>
using namespace std;
int a[500020],n,m,v[5000010],y,k;
bool b[500020]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
	    scanf("%d",&a[i]);
	    if(a[i]==k){m++;b[i]=1;}
	}
	for(int i=1;i<n;i++){
	    for(int j=i+1;j<=n;j++){
	    	int x=0;
	    	bool f=0;
			for(int c=i;c<=j;c++){
			    if(b[c]==1){
			        f=1;
			        break;
			    }
			    x=x^a[c];
		    }
	    	if(x==k&&f==0){
			    m++;
			    for(int c=i;c<=j;c++){b[c]=1;}
		    }
		}
    }  
	printf("%d",m);
    return 0;
} 
