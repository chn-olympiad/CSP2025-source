#include<bits/stdc++.h>
using namespace std;
int arr[110];
int main(){
	int n,m,mao=1,maxn=0,a1,b1,m1,n1;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m*n;i++){
		cin>>arr[i];
		if(i==0) a1=arr[i];
	}
	for(int i=0;i<m*n;i++){
		for(int j=i;j<m*n;j++){
			if(arr[j]>maxn){
				maxn=arr[j];
				mao=j;
			}
		}
		swap(arr[i],arr[mao]);
		maxn=0;
	}
	for(int i=0;i<m*n;i++){
		if(arr[i]==a1){ b1=i;}
	}
	m1=floor(b1/n+1);
	n1=b1%n;
	if(m1%2==0){
		cout<<m1<<' '<<n-n1<<endl;
	}else{
		cout<<m1<<' '<<n1+1<<endl;
	
	}
	
	return 0;
}
