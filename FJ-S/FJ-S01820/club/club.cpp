#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int a[t+1];
	int g[100000][4]={{0}};
	int k=0;
	for(int i=1; i<=t; i++) {
		cin>>a[i];
		k+=a[i];
		for(int j=1; j<=a[i]; j++) {
			for(int k=1; k<=3; k++) {
				cin>>g[j][k];
			}
		}
	}
	int k1[k]={0},k2[k]={0};
	for(int i=1; i<=k; i++) {
		k1[i]=g[i][1];
		k2[i]=g[i][2];
	}
	sort(k1+1,k1+k+1,cmp);
	sort(k2+1,k2+k+1,cmp);
	int sum=0;
	int toto1=0,toto2=0;
	for(int i=1; i<=t; i++) {
		for(int j=1; j<=a[i]; j++) {
			if(toto1==a[i]/2)
			{
				sum+=k2[j];
				continue;	
			}
			if(toto2==a[i]/2)
			{
				sum+=k1[j];
				continue;
			}
			else sum+=max(k1[j],k2[j]);
			toto1++;
			toto2++;
		}
		cout<<sum<<endl;
	}
}
/*1
4
1 0 0
2 0 0
3 0 0
4 0 0
*/
