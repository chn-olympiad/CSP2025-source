#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int a[10][3],b;
		cin >> b;
		int c[10],c1=0,c2=0,c3=0;
		for(int j=0;j<b;j++){
			cin >> a[j][0] >> a[j][1] >> a[j][2];
			int maxn=max(a[j][0],a[j][1]);
			maxn=max(maxn,a[j][2]);
			if(maxn==a[j][0]){
				c[i]=0;
				c1++;
			}
			else if(maxn==a[j][1]){
				c[i]=1;
				c2++;
			}
			else {
				c[i]=2;
				c3++;
			}
		}
		while(c1>b/2){
			int minn = 1e9,minm; 
			for(int j=0;j<b;j++){
				if(minn>a[j][0]){
					minn=a[j][0];
					minm=j;
				}
			}
			if(a[minm][1]>a[minm][2]&&c3<=b/2){
				c[minm]=2;
				c1--;
				c3++;
			}
			else{
				c[minm]=1;
				c1--;
				c2++;
			}
		}
		while(c2>b/2){
			int minn = 1e9,minm; 
			for(int j=0;j<b;j++){
				if(minn>a[j][1]){
					minn=a[j][1];
					minm=j;
				}
			}
			if(a[minm][0]>a[minm][2]&&c3<=b/2){
				c[minm]=2;
				c2--;
				c3++;
			}
			else{
				c[minm]=0;
				c2--;
				c1++;
			}
		}
		while(c3>b/2){
			int minn = 1e9,minm; 
			for(int j=0;j<b;j++){
				if(minn>a[j][2]){
					minn=a[j][2];
					minm=j;
				}
			}
			if(a[minm][0]>a[minm][1]&&c2<=b/2){
				c[minm]=1;
				c3--;
				c2++;
			}
			else{
				c[minm]=0;
				c3--;
				c1++;
			}
		}
		int ans=0;
		for(int j=0;j<b;j++){
			ans+=a[j][c[j]];
		}
		cout << ans << endl;
	}
	return 0;
}
