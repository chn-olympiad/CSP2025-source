#include<bits/stdc++.h>
using namespace std;

constexpr int N=1e5+7;
int n,m,num,c;
int a[N];

bool cmp(int a,int b){
	return a>b;
}


int main(){
	
	cin>>n>>m>>c;
	num=n*m-1;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	sort(a+1,a+num+1,cmp);
	//for(int i=1;i<=num;i++){
	//	cout<<a[i];
	//}
	int mid;
	int l=1,r=num;
	
	//cout<<mid;
	
	while(l<r){
		mid=ceill((l+r)/2);
		if(a[mid]<c){
			r=mid;
		}else if(a[mid]>c){
			l=mid+1;
		}else{
			break;
		}
	}
	//cout<<l<<endl;
	//100 98 97
	cout<<ceill((float)l/n)<<" ";
	
	if((int)(ceill((float)l/n))%2==1){
		if(l%n==0){
			cout<<m;
		}else{
			cout<<l%n;
		}
	}else{
		if(l%n==0){
			cout<<1;
		}else{
			cout<<n-(l%n)+1;
		}
	}
	
	
	return 0;
}
