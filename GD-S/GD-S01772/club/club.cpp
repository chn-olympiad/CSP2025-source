#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[100005],b[100005],c[100005],d[100005],ans[100005]={0};
	int a1=0,b1=0,c1=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
				cin>>a[j]>>b[j]>>c[j];
				d[j]=a[j]+b[j]+c[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(d[k]>d[j]){
					swap(d[k],d[j]);
					swap(a[k],a[j]);
					swap(b[k],b[j]);
					swap(c[k],c[j]);
					
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(a[j]>b[j]&&a[j]>c[j]&&a1<=n/2){
				ans[i]+=a[j];
				a1++;
			}
			else{
				if(b[j]>c[j]&&b1<=n/2){
					ans[i]+=b[j];
					b1++;
				}
				else{
					if(c1<=n/2){
						ans[i]+=c[j];
						c1++;
					}
					
					
				}
			}
			
		}
		a1=0,b1=0,c1=0;
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0*/
