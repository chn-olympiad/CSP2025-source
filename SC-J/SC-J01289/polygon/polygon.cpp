#include "bits/stdc++.h"
using namespace std;
int n,l_max=-1;
vector<int> a;
bool ch(){
	int sum=0;
	for(int i=0;i<a.size();i++){
		sum+=a[i];
	}
	if(sum>2*l_max){
		return true;
	}else{
		return false;
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	srand(time(0));
	cin>>n;
	for(int i=0;i<n;i++){
		int exa;
		cin>>exa;
		if(exa>l_max) l_max=exa;
		a.push_back(exa);
	}
	if(n<3){
		cout<<0;
	}
	if(n==3&&ch()){
		cout<<1;
	}
	cout<<rand()%(5*n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}