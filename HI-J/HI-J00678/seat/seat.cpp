#include<iostream>
#include<vector>
#include"math.h"
using namespace std;

int Max(vector<int> &a){
	int b,c;
	for(int i=0;i<a.size();i++){
		b=max(b,a[i]);
		if(b==a[i]){
			c=i;
		}
	}
	if(c!=0&&a.size()!=1){
		a.erase(a.begin()+c);
	}
	return c;
}

int main(){
	int m,n;
	cin>>n>>m;
	vector<int> a(m*n);
	for(int i=0;i<m*n;i++){
		cin>>a[i]; 
	}
	cout<<endl;
	for(int i=0;i<m;i++){
		bool Break = false;
		for(int q=0;q<n;q++){
			if(Max(a)==0){
				cout<<i<<" "<<1+(-1*(i%2)*q+q);
				Break = true;
				break;
			}
		}
		if(Break){
			break;
		}
	}
	return 0;
}
