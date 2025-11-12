#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("clubin","r",stdin);
	freopen("clubout","w",stdout);
	int t;
	cin>>t;
	int sum[t]={0};
	for(int o=0;o<t;o++){
    	int i;
    	cin>>i;
		int a1[i]={0},a2[i]={0},a3[i]={0},b1[i]={0},b2[i]={0},b3[i]={0},l1=0,l2=0,l3=0,e=i/2;
		for(int l=0;l<i;l++){
			int a,b,c;
			cin>>a>>b>>c;
			if(a==0)
			a=-1e9;
			if(b==0)
			b=-1e9;
			if(c==0)
			c=-1e9;
			a1[l]=a;
			a2[l]=b;
			a3[l]=c;
			if(a==b==c){
				sum[o]=sum[o]+a;
				b1[l]=a;
				b2[l]=b;
				b3[l]=c;
				if(l1<l2&&l1<l3)
				l1++;
				if(l2<l1&&l2<l3)
				l2++;
				if(l3<<l1&&l3<l2)
				l3++;
				else
				l1++;
			}
			if(a>max(b,c)){
				sum[o]=sum[o]+a;
				l1++;
				b1[l]=a;
			}
			if(b>max(a,c)){
				sum[o]=sum[o]+b;
				l2++;
				b2[l]=b;
			}
			if(c>max(a,b)){
				sum[o]=sum[o]+c;
				l3++;
				b3[l]=c;
			}
}
while(l1>e||l2>e||l3>e){
if(l1>e){
	int p=1e9;
	for(int l=0;l<i;l++){
		if(p>b1[l])
		p=b1[l];
		b1[l]=1e9;
		if(a2[l]>a3[l]){
		sum[o]=sum[o]-p+a2[l];
		l2++;
		}
		else if(a3[l]>a2[l]){
			sum[o]=sum[o]-p+a3[l];
			l3++;
		}
		else if(a2[l]==a3[l]){
			sum[o]=sum[o]-p+a2[l];
			if(l2<l3)
				l2++;
				else
				l3++;
		}
	}
	l1--;
}
if(l2>e){
	int p=1e9;
	for(int l=0;l<i;l++){
		if(p>b2[l])
		p=b2[l];
		b2[l]=1e9;
		if(a3[l]>a1[l]){
		sum[o]=sum[o]-p+a3[l];
		l3++;
		}
		else if(a1[l]>a3[l]){
			sum[o]=sum[o]-p+a1[l];
			l1++;
		}
		else if(a1[l]==a3[l]){
			sum[o]=sum[o]-p+a1[l];
			if(l1<l3)
				l1++;
				else
				l3++;
		}
	}
	l2--;
}
	if(l3>e){
	int p=1e9;
	for(int l=0;l<i;l++){
		if(p>b3[l])
		p=b3[l];
		b3[l]=1e9;
		if(a1[l]>a2[l]){
		sum[o]=sum[o]-p+a1[l];
		l1++;
		}
		else if(a2[l]>a1[l]){
			sum[o]=sum[o]-p+a2[l];
			l2++;
		}
		else if(a1[l]==a2[l]){
			sum[o]=sum[o]-p+a1[l];
			if(l1<l2)
				l1++;
			else
			l2++;
		}
	}
	l3--;
}
}
}
for(int o=0;o<t;o++){
	cout<<sum[o]<<endl;
}
	return 0;
}
