#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],b[500005];
long long s=0,z=0;
bool flag=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	if(k==0){
		if(b[1]=1&&b[n]==1){
			if(n>1){
				printf("%d",n/2);
				return 0;
			}
			else{
				printf("%d",0);
				return 0;
			}
		}
		else if(b[1]==0&&b[n]==1){
			int s0=0,s1=0;
			for(int i=1;i<=n;i++){
				if(b[i]==0){
					s0++;
				}
				if(b[i]==1){
					s1++;
				}
			}
			printf("%d",s0+(s1/2));
			return 0;
		}
		else if(b[n]==0){
			printf("%d",n);
			return 0;
		}
	}
	else if(k==1&&b[1]==0&&b[n]==1){
		    int s0=0,s1=0;
			for(int i=1;i<=n;i++){
				if(b[i]==0){
					s0++;
				}
				if(b[i]==1){
					s1++;
				}
			}
			printf("%d",s1);
			return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			s++;
			z=0;
			flag=0;
			continue;
		}
		else if(a[i]!=k){
			if(flag==0){
				flag=1;
				z=a[i];
				continue;
			}
			else{
				z=z^a[i];
				if(z==k){
					s++;
			        z=0;
			        flag=0;
					continue;
				}
			}
		}
	}
	printf("%d",s);
	return 0;
}
