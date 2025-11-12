#include<bits/stdc++.h>
using namespace std;
int t,a[100000],b[100000],c[100000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		int n,sum=0;
		int m[100000];
		scanf("%d",&n);
		int count1=0,count2=0,count3=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			m[i]=max(max(a[i],b[i]),c[i]);
			if(m[i]==a[i]) count1++;
			else if(m[i]==b[i]) count2++;
				else count3++;
			sum+=m[i]; 
		}
		sort(a,a+n);
		sort(b,b+n);
		sort(c,c+n);
		int mid=n/2;
		if(count1>mid){
			sum=sum-a[n-1];
			if(count2<mid&&count3>mid){
				int maxn=max(b[n-2],a[n-2]);
				sum+=maxn;
			}
			if(count2>mid&&count3<mid){
				int maxn=max(a[n-2],c[n-2]);
				sum+=maxn;
			}
			if(count2<mid&&count3<mid){
				int maxn=max(max(b[n-2],c[n-2]),a[n]);
				sum+=maxn;
			}
		}
		if(count2>mid){
			sum=sum-b[n-1];
			if(count1<mid&&count3>mid){
				int maxn=max(a[n-2],b[n-2]);
				sum+=maxn;
			}
			if(count1>mid&&count3<mid){
				int maxn=max(b[n-2],c[n-2]);
				sum+=maxn; 
			}
			if(count1<mid&&count3<mid){
				int maxn=max(max(a[n-2],c[n-2]),b[n]);
				sum+=maxn;
			}
		}
		if(count1>mid){
			sum=sum-c[n-1];
			if(count1<mid&&count2>mid){
				int maxn=max(a[n-2],c[n-2]);
				sum+=maxn;
			}
			if(count1>mid&&count2<mid){
				int maxn=max(b[n-2],c[n-2]);
				sum+=maxn;
			}
			if(count1<mid&&count2<mid){
				int maxn=max(max(a[n-2],c[n]),b[n-2]);
				sum+=maxn;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}}