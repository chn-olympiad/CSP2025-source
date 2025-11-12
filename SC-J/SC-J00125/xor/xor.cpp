#include<bits/stdc++.h>
using namespace std;
int n,k,an=0;
vector<pair<int,int> > ans;
int main(){
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int xorsum=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int t=i;t<=j;t++){
				xorsum^=a[t];
			}
			if(xorsum==k){
				ans.push_back(make_pair(i,j));
				an++;
			}
		}
	}
	for(int i=1;i<ans.size();i++){
		for(int j=i+1;j<ans.size();j++){
			if(i==j){
				an--;
			}
		}
	}
	cout<<an;
	return 0;
}