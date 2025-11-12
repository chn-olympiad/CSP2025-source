#include <bits/stdc++.h>
using namespace std;

int a[10010][3],b[10010][3],c[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	for(int i=0;i<k;i++){
		cin>>b[i][0]>>b[i][1]>>b[i][2];
	}
	for(int i=1;i<=n;i++) c[i]=1;
	int f=1;
	for(int i=1;i<m;i++){
		for(int j=i+1;j<m;j++){
			if(a[j][2]<a[j-1][2]){
				int t=a[j][2];
				a[j][2]=a[j-1][2];
				a[j-1][2]=t;
				t=a[j][1];
				a[j][1]=a[j-1][1];
				a[j-1][1]=t;
				t=a[j][0];
				a[j][0]=a[j-1][0];
				a[j-1][0]=t;
			}
		}
	}
	int s=0;
	for(int i=0;i<n-1;i++){
		s+=a[i][2];
	}
	cout<<s;
	return 0;
	fclose(stdin);
	fclose(stdout);
//	for(int i=0;i<m;i++){
//		cout<<a[i][0]<<' '<<a[i][1]<<' '<<a[i][2]<<endl;
//	}
//	int x=a[0][0];
//	
//	c[1]=0;
//	s=a[0][2];
//	while(f){
//		f=0;
//		for(int i=0;i<n;i++){
//			if(c[i]==1) f=1;
//		}
//		if(a[i][])
//	}
}
