#include<bits/stdc++.h>
using namespace std;
vector<int> s; 
int n=0;
int a[5000];
int sum=0;
void deep(int j){
	s.push_back(j);
	
	int d=0,m=0;
	for(int i:s){
		m=max(a[i],m);
		d+=a[i];
	}
	if(s.size()>=3&&d>m*2){
		sum++;
		sum=sum%998244353;
	}
	
	for(int i=j+1;i<n;i++){
		deep(i);
	}
	s.erase(s.end()-1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++)deep(i);
	cout<<sum;
	return 0;
}
