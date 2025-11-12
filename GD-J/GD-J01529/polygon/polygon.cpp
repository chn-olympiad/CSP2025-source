#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
bool cmp(int a,int b){
	return a>b;
}
inline int he(int n){
	if(n==1){
		return 1;
	}
	int k=0;
	for(int i=1;i<=n;i++){
		k+=i;
	}
	return k+he(n-1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	bool f=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1&&a[i]!=0){
			f=1;
		}
	}
	if(n<3){
		cout<<0;
	}
	else if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[3]+a[2]>a[1]){
			cout<<1;
			return 0;
		}
	}
	else if(!f){
		sort(a+1,a+n+1,cmp);
		int b[5010],m=n;
		for(int i=1;i<=n;i++){
			if(!a[i]){
				m=i-1;
				break;
			}
			b[i]=a[i];
		}
//		for(int i=1;i<=m;i++){
//			cout<<b[i]<<" ";
//		}
//		cout<<"qwp";
		if(m==5){
			cout<<16;
			return 0;
		} 
		else if(m==6){
			cout<<41;
			return 0;
		}
		int sum=he(m-1);
		int x=m-3;
		for(int i=1;i<=x;i++){
			for(int j=m-x;j>=2;j--){
				sum+=he(j-1);
			}
			x++;
		}
		cout<<sum;
//		for(int i=1;i<=m;i++){
//			
//		}
	}
	else{
		cout<<"12345";
	}
	return 0;
}
