#include <bits/stdc++.h>
using namespace std;
int a[114514],b[114514],c[114514],num[114514],sum=0,temp,n,k=1;
bool cmp(int a,int b){
	if(a!=b){
		return a>b;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--){
		cin>>n;
		if(n==2){
			for(int i=1;i<=n;i++){
				cin>>a[i]>>b[i]>>c[i];
		}	
		}
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		//for(int i=1;i<=n;i++){
			//cout<<a[i]<<endl;
		//}
		//cout<<endl;
		//for(int i=1;i<=n;i++){
			//cout<<b[i]<<endl;
		//}
		//cout<<endl;
		//for(int i=1;i<=n;i++){
			//cout<<c[i]<<endl;
		//cout<<endl;
		for(int i=1;i<=n/2;i++){
			num[k]=a[i];
			num[k+1]=b[i];
			num[k+2]=c[i];
			k+=3;
		}
		sort(num+1,num+n/2*3+1,cmp);
		for(int i=1;i<=n;i++){
			sum+=num[i]; 
		}
		cout<<sum<<endl;
		k=0;
		//for(int i=1;i<=n/2*3;i++){
			//cout<<num[i]<<endl;
		//}
	}
}
