#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N],b[N],c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){		
			scanf("%d%d%d",&a[i],&b[i],&c[i]);	
		}
		if(n==2){	
		    int maxx=-1;			
	        maxx=max(a[1]+b[2],max(a[1]+c[2],max(b[1]+a[2],max(b[1]+c[2],max(c[1]+a[2],max(c[1]+b[2],maxx))))));
		    printf("%d",maxx);
			continue;
		}
		int ans=0,ans1=0,ans2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0&&b[i]==0) ans++;
			if(a[i]==0&&c[i]==0) ans1++;
			if(b[i]==0&&c[i]==0) ans2++;
		} 
		if(ans==n){
		sort(c+1,c+n+1);
		int sum=0;
		for(int i=n;i>n/2;i--){
		   	sum+=c[i]; 
		}
		printf("%d\n",sum);
		continue;
		}
		else if(ans1==n){
		sort(b+1,b+n+1);
		int sum=0;
		for(int i=n;i>n/2;i--){
		   	sum+=b[i]; 
		}
		printf("%d\n",sum);
		continue;
		}
		else if(ans2==n){
		sort(a+1,a+n+1);
		int sum=0;
		for(int i=n;i>n/2;i--){
		   	sum+=a[i]; 
		}
		printf("%d\n",sum);
		continue;
		}
		else{
			int sum=0;
			for(int i=1;i<=n;i++){
				sum+=max(a[i],max(b[i],c[i]));
			}
			printf("%d\n",sum);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
