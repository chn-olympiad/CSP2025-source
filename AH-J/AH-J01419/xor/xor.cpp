#include<iostream>
using namespace std;
int n,k;
int a[500005];
int ans,x;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor,out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		ans=a[i];
		if(ans==k){
			x++;
		}else{
		    for(int j=i+1;j<=n;j++){
			    if((ans^a[j])==k){
				    x++;
				    i=j;
				    break;
			    }else {
				    ans^=a[j];
			    }
		    }
		}
	}
	printf("%d",x);
    return 0;
}
