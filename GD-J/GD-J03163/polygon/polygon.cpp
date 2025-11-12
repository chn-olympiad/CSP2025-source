#include<bits/stdc++.h>

using namespace std;

const int modder=998244353;

long long sumarr(int*arr,int arrS,int arrE){
	long long ret;
	for(int i=arrS;i<=arrE;i++){
		ret+=arr[i];
	}
	return ret;
}
int maxarr(int*arr,int arrS,int arrE){
	int ret=0;
	for(int i=arrS;i<=arrE;i++){
		ret=max(ret,arr[i]);
	}
	return ret;
}
bool isPolygon(int* sticks,int stickStart,int stickEnd){
	long long s=sumarr(sticks,stickStart,stickEnd);
	int m=maxarr(sticks,stickStart,stickEnd);
	cout<<"";
	return s>2*m;
}
void bl(int* arr,int arrS,int arrE){
	cout<<"";
	for(int i=arrS;i<=arrE;i++){
		cout<<"";
	}
	cout<<"";
}
int arrangement(int n,int m){
	int ret=1;
	for(int i=n;i>=n-m+1;i--){
		ret*=i;
	}
	return ret;
}
int combination(int n,int m){
	return arrangement(n,m)/arrangement(m,m);
}


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,counter=0;
	cin>>n;
	int arr[n],chosen[n];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				counter+=isPolygon(arr,i,j);
				bl(arr,i,j);
				if(counter>=900000000){
					counter=counter%modder;
				}
			}
		}
		cout<<counter;
	} else {
		int a[n];
		for(int i=3;i<=n;i++){
			a[i]=combination(n,i);
		}
		cout<<sumarr(a,3,n);
	}
	return 0;
}
