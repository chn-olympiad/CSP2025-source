#include<bits/stdc++.h>
using namespace std;
int a[100000][3];
int f(int i){
	int max=0,x=0;
	for(int j=0;j<3;j++){
	    if(a[i][j]>max){
	        max=a[i][j];
			x=j;
		}
	}
	return x;
}
int main(){
	int t;
	cin>>t;
	for(int q=0;q<t;q++){
		int n,m=0;
		cin>>n;
		for(int i=0;i<n;i++)for(int j=0;j<3;j++)cin>>a[i][j];
		int b[3];
		for(int j=0;j<3;j++)b[j]=0;
		for(int i=n-1;i>=0;i--){
			int x1=f(i);
			if(b[x1]<n/2){
				b[x1]+=1;
				m+=a[i][x1];
			}else{
				a[i][x1]=0;
				int x2=f(i);
			    if(b[x2]<n/2){
					b[x2]+=1;
					m+=a[i][x2];
				}else {
				    a[i][x2]=0;
				    int x3=f(i);
				    b[x3]+=1;
				    m+=a[i][x3];
			    }
			}
		}
		cout<<m;
	}
	return 0;
}
