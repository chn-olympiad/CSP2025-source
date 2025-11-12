#include<bits/stdc++.h>
using namespace std;
long long n,N,arr2[100001],arr[100001],A,B,C,sum;
char arr3[1000001];
struct{
	int a,b,c; 
}arr1[1000001];
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		N=arr[i]/2;
		for(int j=1;j<=arr[i];j++){
			cin>>arr1[j].a>>arr1[j].b>>arr1[j].c;
		}
		for(int j=arr[i];j>=1;j--){
			if(arr1[j].a>arr1[j].b&&arr1[j].a>arr1[j].c){
				if(A<N){
					A++;
					sum+=arr1[j].a;
				}else if(arr1[j].b>arr1[j].c&&B<=N){
					B++;
					sum+=arr1[j].b;
				}else{
					C++;
					sum+=arr1[j].c;
				}
			}else if(arr1[j].b>arr1[j].a&&arr1[j].b>arr1[j].c){
				if(B<N){
					B++;
					sum+=arr1[j].b;
				}else if(arr1[j].a>arr1[j].c&&A<=N){
					A++;
					sum+=arr1[j].a;
				}else{
					C++;
					sum+=arr1[j].c;
				}
			}else if(arr1[j].c>arr1[j].a&&arr1[j].c>arr1[j].b){
				if(C<N){
					C++;
					sum+=arr1[j].c;
				}else if(arr1[j].a>arr1[j].b&&A<=N){
					A++;
					sum+=arr1[j].a;
				}else{
					B++;
					sum+=arr1[j].b;
				}
			}
		}
		arr2[i]=sum;
		A=0;
		B=0;
		C=0;
		sum=0; 
	}
	for(int i=1;i<=n;i++){
		cout<<arr2[i]<<endl;
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
