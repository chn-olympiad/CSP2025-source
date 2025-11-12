#include<bits/stdc++.h>
using namespace std;
int t,n,A[10];
int d,e,f;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		d=0;
		f=0;
		e=0;
		n=0;
		int a[10005][1]={0};
		int b[10005][1]={0};
		int c[10005][1]={0};
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j][0];
			cin>>b[j][0];
			cin>>c[j][0];
		}
		sort(a[0],a[n]);
		for(int k=0;k<n/2;k++){
			d+=a[n/2-k][0];
		}
		sort(b[0],b[n]);
		for(int k=0;k<n/2;k++){
			e+=b[n/2-k][0];
		}
		sort(c[0],c[n]);
		for(int k=0;k<n/2;k++){
			f+=c[n/2-k][0];
		}
		A[i]=d+e+f+1;
	}
	for(int i=0;i<t;i++){
		cout<<A[i]<<"\n";
	}
	return 0;
} 
