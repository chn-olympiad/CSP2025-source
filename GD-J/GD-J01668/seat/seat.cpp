#include <iostream>
#include <cstdio> 
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	// Write your code
	int n,m;
	// n hang  m lie
	cin>>n>>m;
	int siz=n*m;
	int sco[n*m];
	for(int i=0;i<siz;++i){
		cin>>sco[i];
	} 
	sort(sco+1,sco+siz,cmp);
	
	int o=lower_bound(sco+1,sco+siz,sco[0],cmp)-sco-1;
	int o1=o/m;
	int o2=o%m;
	if(o1&0x01){
		o2=n-o2;
	}else{
		++o2;
	}
	cout<<o1+1<<' '<<o2<<'\n';
	
	return 0;
}
