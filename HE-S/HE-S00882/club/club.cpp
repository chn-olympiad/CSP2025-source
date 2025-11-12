#include<bits/stdc++.h>
using namespace std;
int a[10000],b[10000],c[10000],v[10000];
int n,s,d,sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int k;
	cin>>k;
	for(int i=1;i<=k;i++){
		int m;
		cin>>m;
		n=0;s=0;d=0;
		sum=0;
		for(int j=1;j<=m;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(a[j]>b[j]&&a[j]>c[j]){
				n++;
				sum=sum+a[j];
			}
			else if(b[j]>c[j]){
				s++;
				sum=sum+b[j];
			}
			else{
				d++;
				sum=sum+c[j];
			}
			if(n>m/2){
				int sum1,sum2;
				sum = sum-a[j]-a[j-1];
				sum1=sum+a[j];
				sum2=sum+a[j-1];
				sum=max(max(sum1+b[j-1],sum1+c[j-1]),max(sum2+b[j],sum2+c[j]));
				n--;
				if(sum == sum1+b[j-1])	s++;
					else if	(sum == sum2+b[j]) s++;
						else d++;
					}
			else if(s>m/2){
				int sum1,sum2;
				sum = sum-b[j]-b[j-1];
				sum1=sum+b[j];
				sum2=sum+b[j-1];
				sum=max(max(sum1+a[j-1],sum1+c[j-1]),max(sum2+a[j],sum2+c[j]));
				s--;
				if(sum == sum1+a[j-1]) n++;
				else if(sum == sum2+a[j]) n++;
				else d++;
					}
			else if(d>m/2){
					int sum1,sum2;
					sum = sum-c[j]-c[j-1];
					sum1=sum+c[j];
					sum2=sum+c[j-1];
					sum=max(max(sum1+b[j-1],sum1+a[j-1]),max(sum2+b[j],sum2+a[j]));
					d--;
					if(sum == sum1+b[j-1]) s++;
					else if(sum == sum2+b[j]) s++;
					else n++;
					}
				}
			v[i]=sum;
	}
		for(int i=1;i<=k;i++){
			cout<<v[i]<<endl;
		}
	return 0;
} 
