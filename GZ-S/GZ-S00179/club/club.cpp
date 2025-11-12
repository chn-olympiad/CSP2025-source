//GZ-S00179 安顺市第一高级中学 张金融 
#include<iostream>
using namespace std;
int A[55555],B[55555],C[55555],T[55555];
int maxa(int a,int b,int c){
	if(a>=b&&a>=c) return a;
	if(b>=a&&b>=c) return b;
	if(c>=a&&c>=b) return c; 
}
int main(){
	int t;cin>>t;
	int a;a=t; 
	for(int i=0;i<t;i++){
		int n;cin>>n;
		int ans=0;
		for(int i=0;i<n;i++){
			cin>>A[i]>>B[i]>>C[i];
			ans+=maxa(A[i],B[i],C[i]);
			if(i==n-1) T[a--]=ans;
	}
}
	for(int i=t;i>0;i--){
		cout<<T[i]<<endl;
	}
	return 0;
}



