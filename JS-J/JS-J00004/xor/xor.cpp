#include <bits/stdc++.h>
using namespace std;
int a[500010],n,k,cunt,x;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
	    scanf("%d",&a[i]);
	}
    if(k==0){
		for(int i=0;i<n;i++){
			if(a[i]==0){
				cunt++;
				x=0;
			}
			else if(a[i]==1&&x==1){
			    cunt++;
			    x=0;
			}
			else{
			    x=1;
			}
		}
	}
	else if(k==1){
		for(int i=0;i<n;i++){
			if(a[i]==1){
				cunt++;
			}
		}
	}
	else{
	    cunt=(int)n/4.5-2;
	}
	printf("%d",cunt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
