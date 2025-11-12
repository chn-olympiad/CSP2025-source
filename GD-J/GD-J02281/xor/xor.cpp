#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],num,sum;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum=a[i];
			for(int o=i+1;o<=j;o++){
				sum=sum^a[o];
			}
			//cout<<"sum="<<sum<<" k="<<k<<" i="<<i<<" j="<<j<<endl;
			if(sum==k){
				num++;
			}
		}
	}
	printf("%d",num);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
