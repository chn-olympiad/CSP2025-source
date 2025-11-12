#include<bits/stdc++.h>
using namespace std;
int n,a[5005],max=0;
int f[5005]={0},f1=1,f2=0,f3=0;
int s3(int x,int y){
	f[f1]=a[y];f1++;
	if(x-1!=0){
		x--;f3++;
		return s2(x,f3)+a[y];
	}
}
int s2(int x,int y){
	f[f1]=a[y];f1++;
	if(x-1!=0){
		x--;f2++;
		return s3(x,f2)+a[y];
	}
}
void s1(int x){
	int mn=0;	
	for(int i=1;i<=n;i++)
		mn+=a[i];
	if(x==n)
		if(mn/a[n]>=2)max++;
	else for(int i=1;i<=n-x;i++){
		for(int j=1;j<=n;j++){
			int mx=mn-s2(i,j);
			sort(f+1,f+f1);
			if(mx/f[f1-1]>=2)max++;
		}
	}
}
int main(){
	fronpen("polygon.in","r",stdin);
	fronpen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int mn=n;mn>=3;mn--){
		s1(mn);
	}
	cout<<max;
	return 0;
}
