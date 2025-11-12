#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<long long> a(n*m,0);
	vector<vector<long long>> mp(n,vector<long long>(m));
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int temp=a[0];
	sort(a.begin(),a.end(),cmp);
	int j=0;
	int cnt=0;
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				if(a[cnt++]==temp){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
		}else{
			for(int j=n-1;j>=0;j--){
				if(a[cnt++]==temp){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
		}
	}
	return 0;
}
