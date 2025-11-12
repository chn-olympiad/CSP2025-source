#include<bits/stdc++.h>
using namespace std;

vector<int> arr;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m*n;i++){
		int a;
		cin>>a;
		arr.push_back(a);
	}
	int x = arr[0];
	sort(arr.begin(),arr.end(),greater<int>());
	
	int index = 0;	
	for(int i=0;i<m*n;i++){
		if(arr[i]==x)index = i;
	}
	index++;
	int c = (index+n-1)/n;
	int r;
	if(c%2==1){
		index -= (c-1)*n;
		r = index;
	}
	else{
		index -= (c-1)*n;
		r = n-index+1;
	}
	cout<<c<<' '<<r;
	
	
	
	
	
	return 0;
}