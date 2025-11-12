#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int b[1000001];
int c[1000001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int z;
	cin>>z;
	for(int k=0;k<z;k++){
		int n;
		cin>>n;
		if(n==2){
			int a1,a2,a3,b1,b2,b3;
			cin>>a1>>a2>>a3>>b1>>b2>>b3;
			int max1;
			max1=max(a1+b2,a1+b3);
			max1=max(max1,a2+b1);
			max1=max(max1,a2+b3);
			max1=max(max1,a3+b1);
			max1=max(max1,a3+b2);
			cout<<max1;
		}
		else{
			int g=0;
			for(int i=0;i<n;i++){
				cin>>a[i]>>b[i]>>c[i];
				if(b[i]>0) g=1;
			}
			if(g==0){
				sort(a,a+n,cmp);
				int sum=0;
				for(int i=0;i<n/2-1;i++){
					sum+=a[i];
				}
				cout<<sum;
			}
			//else{
				
			//}
		}
	}
	return 0;
}

