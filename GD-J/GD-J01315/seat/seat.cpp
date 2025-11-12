#include<bits/stdc++.h>
using namespace std;
long long a,s,d[100000],f=0,g,h,j,k,l;
//char c[10000000];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>g>>h;
	f=g*h;
	for(long long p=1;p<=f;p++){
		cin>>d[p];
		if(d[p]>d[1]){
			j++;
		}
	}
	if(j/g%2==0){
		cout<<j/g+1<<' '<<j%g+1;
	}else if(j/g%2==1){
		cout<<j/g+1<<' '<<g-j%g;
	}
	return 0;
}
