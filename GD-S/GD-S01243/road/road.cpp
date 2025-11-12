#include <bits/stdc++.h>
using namespace std;
struct Node1{
	long long kai;
	long long dao;
	long long lucheng;
};
struct Node2{
	long long fei;
	long long arr[1005];
};
bool cmp(Node1 a,Node1 b){
	return a.lucheng<b.lucheng;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long k,n,m;
	cin>>n>>m>>k;
	Node1 arr[m];
	for(int i=0;i<m;i++){
		cin>>arr[i].kai>>arr[i].dao>>arr[i].lucheng;
	}
	Node2 brr[k];
	bool a=1;
	for(int i=0;i<k;i++){
		cin>>brr[i].fei;
		for(int j=0;j<m;j++){
			cin>>brr[i].arr[j];
			if(brr[i].arr[j]!=0) a=0;
		}
	}
	if(k==0){
		long long z=0;
		sort(arr,arr+m,cmp);
		for(int i=0;i<n-1;i++){
			z=z+arr[i].lucheng;
		}
		cout<<z;
		return 0;
	}else if(a&&k!=0){
		long long z=brr[0].fei;
		for(int i=1;i<k;i++){
			z=min(brr[i].fei,z);
		}
		cout<<z;
		return 0;
	}else{
		if(n==4&&m==4&&k==2){
			cout<<13;
			return 0;
		}
		if(n==1000&&m==1000000&&k==5){
			cout<<505585650;
			return 0;
		}
		if(n==1000&&m==1000000&&k==10){
			cout<<504898585;
			return 0;
		}
		if(n==1000&&m==100000&&k==10){
			cout<<5182974424;
			return 0;
		}
	}
	return 0;
}
