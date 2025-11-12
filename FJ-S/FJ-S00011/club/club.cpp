#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5];
int m1[50005],m2[50005],m3[50005];
int cha[100005];
bool f2,f3;
bool pd(int a,int b,int c,int d){
	if(a==b && b==c) return 1;
	if(a==b && b==d) return 1;
	if(a==c && c==d) return 1;
	if(b==c && c==d) return 1;
	return 0;
}
void solve2(){
	int maxx=INT_MIN;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(i==j) continue;
			maxx=max(maxx,a[1][i]+a[2][j]);
		}
	}
	cout<<maxx<<endl;
}
void solve4(){
	int maxx=INT_MIN;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			for(int l=1;l<=3;l++){
				for(int k=1;k<=3;k++){
					if(pd(i,j,l,k)==1) continue;
					maxx=max(maxx,a[1][i]+a[2][j]+a[3][l]+a[4][k]);
				}
			}
		}
	}
	cout<<maxx<<endl;
}
void solvef2(){
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n-i+1;j++){
			if(a[j-1][1]<a[j][1]){
				swap(a[j-1][1],a[j][1]);
			}
		}
	}
	int maxx=0;
	for(int i=1;i<=n/2;i++) maxx+=a[i][1];
	cout<<maxx<<endl;
}
void solvef3(){
	for(int i=1;i<=n/2;i++) m1[i]=a[i][1];
	for(int i=n/2;i<=n;i++) m2[i]=a[i][2];
	for(int i=1;i<=n;i++) cha[i]=a[i][1]-a[i][2];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][2]>0) f2=1;
				if(a[i][3]>0) f3=1; 
			}
		}
		if(n==2){
			solve2();
			continue;
		}else{
			if(n==4){
				solve4();
				continue;
			}
		}
		if(f3==0){
			if(f2==0) solvef2();
			else solvef3();
			continue;
		}
	}
	return 0;
}
