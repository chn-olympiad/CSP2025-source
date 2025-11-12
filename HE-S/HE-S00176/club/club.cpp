#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3],b[3];
long long abc(int x,int y){
	if(x==n) return 0;
	long long A=abc(x+1,0),B=abc(x+1,1),C=abc(x+1,2);
	if(b[0]>=n/2&&b[1]<n/2&&b[2]<n/2){
		if(B>C) b[1]++;
		else b[2]++;
		return a[x][y]+max(B,C);
	}
	if(b[0]<n/2&&b[1]>=n/2&&b[2]<n/2){
		if(A>C) b[0]++;
		else b[2]++;
		return a[x][y]+max(A,C);
	}
	if(b[0]<n/2&&b[1]<n/2&&b[2]>=n/2){
		if(A>B) b[0]++;
		else b[1]++;
		return a[x][y]+max(A,B);
	}
	if(b[0]>=n/2&&b[1]>=n/2&&b[2]<n/2){
		b[2]++;
		return a[x][y]+C;
	}
	if(b[0]>=n/2&&b[1]<n/2&&b[2]>=n/2){
		b[1]++;
		return a[x][y]+B;
	}
	if(b[0]<n/2&&b[1]>=n/2&&b[2]>=n/2){
		b[0]++;
		return a[x][y]+A;
	}
	if(A>B&&A>C) b[0]++;
	if(B>A&&B>C) b[1]++;
	if(C>A&&C>B) b[2]++;
	return a[x][y]+max(max(A,B),C);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		cout<<max(max(abc(0,0),abc(0,1)),abc(0,2))<<endl;
		b[0]=b[1]=b[2]=0;
	}
	return 0;
}
