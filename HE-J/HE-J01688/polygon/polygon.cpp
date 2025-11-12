#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
	freopen("ploygon1.in","r",stdin);
	freopen("ploygon1.out","w",stdout);
//	ofstream out;
//	out.open("1.txt");
	int n;
	cin>>n;
	int a[n+1];
//	out<<"start reading!\n";
	for(int i = 1;i<=n;i++){
		cin>>a[i];
//		out<<"read:"<<a[i]<<"\n";
	}
//	out<<"end!\n";
	sort(a+1,a+1+n);
//	out<<"finish sort!\n";
	int maxx=a[n]<<1;
//	out<<"maxx is "<<maxx<<"\n";
	int cnt=0;
	while(next_permutation(a+1,a+n)){
		int sum=0;
//		out<<"this permutation is :";
		for(int i = 1;i<n;i++){
//			out<<a[i]<<" ";
			sum+=a[i];
		}
//		out<<"\nsum is "<<sum<<"\n";
		if(sum<maxx){
			cnt++;
//			out<<"OK! cnt++!\n";
		}
	}
//	out<<"ans is "<<cnt<<"\n";
	cout<<cnt;
	return 0;
} 
