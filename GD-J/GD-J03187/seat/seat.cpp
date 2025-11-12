#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> arr(n*m);
	for(int i=0;i<n*m;i++){
		cin>>arr[i];
	}
	int p=0;
	while(1){
		p++;
		int mx=0;
		for(int i=0;i<arr.size();i++){
			if(arr[i]>arr[mx]){
				mx=i;
			}
		}
		if(mx==0){
			break;
		}
		arr.erase(arr.begin()+mx);
	}
	cout<<(p-1)/n+1<<' ';
	if(((p-1)/n+1)%2){
		cout<<(p-1)%n+1;
	}else{
		cout<<n-((p-1)%n);
	}
	return 0;
}

