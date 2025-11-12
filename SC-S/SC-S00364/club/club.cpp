#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n[10]={};
int a[10][N][3];
int h[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0,tt=0,ttt=0;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n[i];
		for(int j=0;j<n[i];j++){
		    cin>>a[i][j][0];
			cin>>a[i][j][1];
			cin>>a[i][j][2];
			if(a[i][j][0]!=0)
				tt=1;
			if(a[i][j][0]!=0||a[i][j][1]!=0)
				ttt=1;
		}
	}
	if(ttt=0){
		for(int i=0;i<t;i++){
			int sum=0,summax=0;
			int ss=0,e=0,g=n[i];
			int summ=0;
			for(int j=0;j<n[i];j++)
				h[j]=a[i][j][0];
			sort(h+0,h+0+n[i]);
			for(int k=n[i]-1;k>=n[i]/2;k++)
				summ+=a[i][k][0];
			cout<<summ;
		}
	}
	for(int i=0;i<t;i++){
		int sum=0,summax=0;
		int ss=0,e=0,g=n[i];
		while(ss<n[i]){
			int maxs=0,maxg=0;
			int maxsb=0,maxgb=0;
			for(int j=0;j<g;j++){
			if(a[i][j][e]>maxs){
					maxs=a[i][j][e];
					maxg=j;
				}	
			}
			int maxgg=maxg,maxss=maxs;
			for(int k=0;k<g;k++){
				if(maxsb<a[i][k][e]<=a[i][maxg][e]){
					maxsb=a[i][k][e];
					maxgb=k;
					}
				}
				if(a[i][maxgb][e]+a[i][maxg][e+1]>a[i][maxg][e]&&a[i][maxgb][e]+a[i][maxg][e+1]>a[i][maxg][e]+a[i][maxgb][e+1]&&e!=2){
					maxs=maxsb;
					maxg=maxgb;
				}
			a[i][maxg][0]=-1,a[i][maxg][1]=-1,a[i][maxg][2]=-1;
			sum+=maxs;
			e=(e+1)%3;
			ss+=1;
		}
		cout<<sum<<"\n";
		}
	return 0;
} 