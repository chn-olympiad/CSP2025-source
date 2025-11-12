#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum=0;
int cmp(int thx,int thy){
	return thx>thy;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int p=a[i]+a[j];
			int b=a[i],c=a[j];
			a[i]=0;
			a[j]=0;
			for(int k=j+1;k<=n;k++){
				if(a[k]!=0 && p>a[k]) sum++;
			}
			a[i]=b;
			a[j]=c;
		}
	}
	cout<<sum;
	return 0;
}
