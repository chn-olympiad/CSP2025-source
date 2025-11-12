#include<bits/stdc++.h>
using namespace std;
int t,n,o,m[100000],a[100000],b[100000],c[100000],sum=0;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t>>n;
for(int w=0;w<t;w++){
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(a[i]>b[i]&&b[i]>c[i]){
			o=a[i];
		}else if(a[i]>c[i]&&c[i]>b[i]){
			o=a[i];
		}else if(b[i]>a[i]&&a[i]>c[i]){
			o=b[i];
		}else if(b[i]>c[i]&&c[i]>a[i]){
			o=b[i];
		}else if(c[i]>a[i]&&a[i]>b[i]){
			o=c[i];
		}else if(c[i]>b[i]&&b[i]>a[i]){
			o=c[i];
		}
		sum=sum+o;
		o=0;
		for(int i=0;i<n;i++){
			m[i]=sum;
		}
		sum=0;
	}
	
}
for(int i=0;i<n;i++){
cout<<m[i];
}

fclose(stdin);
fclose(stdout);
return 0;
}
