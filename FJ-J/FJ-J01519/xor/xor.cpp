#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor6.in","r",stdin);
	freopen("xor6.out","w",stdout);
	int n,k,a[500003],d=0,e=0;
	int c1[100003],c2[100003];
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			d=a[i];
			for(int c=i+1;c<=j;c++){
				d=d^a[c];
			}
			if(d==k){
				if(e>0){
					for(int x=1;x<=e;x++){
						if(i<c1[x]&&j<c1[x]&&x==e){
							e++;
							c1[e]=i;
							c2[e]=j;
						}
						else if(i>c2[x]&&j>c2[x]&&x==e){
							e++;
							c1[e]=i;
							c2[e]=j;
						}
						else{
							if(i<c1[x]&&j<c1[x]&&x==e){
							e=e;
							}
							else if(i>c2[x]&&j>c2[x]&&x==e){
							e=e;
							}
							else{
								break;
							}
						}
					}
				}
				else{
				e++;
				c1[e]=i;
				c2[e]=j;	
				}
			}
		}
	}
	printf("%d",e);
    fclose(stdin);
	fclose(stdout);
	return 0;
}
