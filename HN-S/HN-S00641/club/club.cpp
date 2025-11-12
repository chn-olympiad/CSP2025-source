#include<bits/stdc++.h>
#define MM 100005
using namespace std;
int n,t,nn,d[MM][3],mx;
bool bb[MM],av[MM];
int a[MM][3],c[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				if(c[k]>n/2){
					continue;
				}
				if(a[j][k]+d[j-1][k]>d[j][k-1]){
					d[j][k]=a[j][k]+a[j][k];
					c[k]++;
				}else{
					d[j][k]=d[j][k-1];
				}
			}
		}
		cout<<mx;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
