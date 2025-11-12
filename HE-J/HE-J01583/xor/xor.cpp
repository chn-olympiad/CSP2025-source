#include<bits/stdc++.h>
using namespace std;
int b[900000],c[900000],a[900000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,as=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i]^b[i-1];
		if(a[i]==1){
			as++;
		}
		b[1]=a[1];
	}
	if(k==0&&as==n){
		if(n==2){
			printf("1");
			return 0;
		}else if(n<2){
			printf("0");
			return 0;
		}
		else{
			printf("%d",n/2);
			return 0; 
		}
	}
	if(a[1]==k){
		ans++;c[1]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(c[j]==1){
				break;
			}
			int su=b[i]^b[j];
			if(su==k){
				ans++;//cout<<j<<" "<<i<<endl; 
				c[i]=1;c[j]=1;
			}
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
