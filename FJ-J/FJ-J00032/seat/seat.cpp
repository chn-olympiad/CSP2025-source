#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,a=0,in=0,s=0,out_1=0,out_2=0;
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;i++){
		cin>>in;
		if(in>a){
			s++;
		}
	}
	out_1=s/n;
	out_1+=1;
	if(out_1%2==0){
		out_2=n - s%n;
	}else{
		out_2=(s%n)+1;
	}
	cout<<out_1<<" "<<out_2;
}
