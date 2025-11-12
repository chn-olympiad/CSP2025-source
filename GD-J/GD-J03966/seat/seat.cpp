#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	int h,l;
	freopen("r","seat.in",stdin);
	freopen("w","seat.out",stdout);
	cin>>h>>l;
	int n=h*l;
	int arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	int r=arr[1];
	sort(arr+1,arr+1+n,cmp);
	int pos=0;
	for(int i=1;i<=n;i++){
		if(arr[i]==r){
			pos=i; 
		}
	}
	int ansh=pos%(h*2);
	if(ansh>h){
		ansh=h-(ansh-h)+1;
	}
	int kj=ansh;
	if(ansh==0){
		ansh=h;
	}
	int ansl=pos/h;
	if(kj>0 && kj!=h){
		ansl++;
	}
	
	cout<<ansl<<" "<<ansh<<endl;
}
