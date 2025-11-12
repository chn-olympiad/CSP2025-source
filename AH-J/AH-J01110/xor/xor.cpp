#include<bits/stdc++.h>
using namespace std;
int n,k,b[500005],s=1,s1=1,a[250005][3],x,wc;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==k)wc++;
		if(b[i]!=1)s=0;
		//else if(0<=b[i]&&b[i]<=1)s1=0;
	}
	//cout<<wc<<"\n";
	for(int i=1;i<=n;i++){
		long long sum=b[i];
		if(sum==k){
			x++;
			a[x][1]=i;
			a[x][2]=i;
		}
		for(int j=i+1;j<=n;j++){
			sum=(sum^b[j]);
			if(sum==k){
				x++;
				a[x][1]=i;
				a[x][2]=j;
			}
		}
	}
	/*for(int i=1;i<=x;i++){
		cout<<a[i][1]<<" "<<a[i][2]<<"\n";
	}*/
	int r,maxn=INT_MIN;
	for(int i=1;i<=x;i++){
		r=a[i][2];
		int sum=1;
		for(int j=i+1;j<=x;j++){
			if(a[j][1]>r){
				r=a[j][2];
				sum++;
			}
		}
		maxn=max(maxn,sum);
	}
	printf("%d",max(maxn,wc));
	return 0;
}
