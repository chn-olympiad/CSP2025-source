#include <bits/stdc++.h>
using namespace std;
int A[100001],B[100001],C[100001],A1[100001],B1[100001],C1[100001];
int arr[6];

int main(){
freopen("club.in","r","stdin");
freopen("club.out","w","stdout");
long long t;
cin>>t;
for (long long i=0;i<t;i++){
	long long n,j1=0,ans=0;
	cin>>n;
	for (long long j=0;j<n;j++){
		cin>>A[j]>>B[j]>>C[j];
	}
	for (long long j=0;j<n;j++){
		for (long long j1=0;j1<n;j1++){
			if (A1[j1]<A1[j1+1]){
				int a=A1[j1],b=A1[j1+1],c;
				c=a;
				a=b;
				b=c;
				A1[j1]=a;
				A1[j1+1]=b;
			}
		}
	}
	j1=0;
	for (long long j=0;j<n;j++){
		for (long long j1=0;j1<n;j1++){
			if (B1[j1]<B1[j1+1]){
				int a=B1[j1],b=B1[j1+1],c;
				c=a;
				a=b;
				b=c;
				B1[j1]=a;
				B1[j1+1]=b;
			}
		}
	}
	j1=0;
	for (long long j=0;j<n;j++){
		for (long long j1=0;j1<n;j1++){
			if (C1[j1]<C1[j1+1]){
				int a=C1[j1],b=C1[j1+1],c;
				c=a;
				a=b;
				b=c;
				C1[j1]=a;
				C1[j1+1]=b;
			}
		}
	}
j1=0;
	for (long long j=0;j<n;j++){
		if (max(max(A[j],B[j]),C[j])!=A[j]){
			A[(n/2)-1]=0;
				for (long long j=0;j<n;j++){
		for (long long j1=0;j1<n;j1++){
			if (A1[j1]<A1[j1+1]){
				int a=A1[j1],b=A1[j1+1],c;
				c=a;
				a=b;
				b=c;
				A1[j1]=a;
				A1[j1+1]=b;
			}
		}
	}
}
	else{
		ans+=A[j];
		A[j]=0;
		B[j]=0;
		C[j]=0;
	}
	}
j1=0;
	for (long long j=0;j<n;j++){
		if (max(max(A[j],B[j]),C[j])!=B[j]){
				B[(n/2)-1]=0;
				j1=0;
	for (long long j=0;j<n;j++){
		for (long long j1=0;j1<n;j1++){
			if (B1[j1]<B1[j1+1]){
				int a=B1[j1],b=B1[j1+1],c;
				c=a;
				a=b;
				b=c;
				B1[j1]=a;
				B1[j1+1]=b;
			}
		}
	}
		}
	else{
		ans+=B[j];
		A[j]=0;
		B[j]=0;
		C[j]=0;
	}
	}
	
	for (long long j=0;j<n;j++){
		ans+=C[j];
		A[j]=0;
		B[j]=0;
		C[j]=0;
	}

	arr[i]=ans;
}
for (long long i=0;i<t;i++){
	cout<<arr[i]<<endl;
}
return 0;
}
