#include <bits/stdc++.h>
#include <cmath>
#include <stdio.h>
using namespace std;
long long t=0,n=0;
long long summax=0;
struct me{
	long long one;
	long long two;
	long long three;
}me[1001];
int jisuan(long long peo,long long club1,long long sum,long long oneme,long long twome,long long threeme){
	if(sum>summax) summax=sum;
	if(peo>n) return sum;
	if(club1==1 &&oneme<n/2+1){
		jisuan(peo+1,1,sum+me[peo].one,oneme+1,twome,threeme);
		jisuan(peo+1,2,sum+me[peo].one,oneme+1,twome,threeme);
		jisuan(peo+1,3,sum+me[peo].one,oneme+1,twome,threeme);
	}
	if(club1==2 &&twome<n/2+1){
		twome++;
		jisuan(peo+1,1,sum+me[peo].two,oneme,twome+1,threeme);
		jisuan(peo+1,2,sum+me[peo].two,oneme,twome+1,threeme);
		jisuan(peo+1,3,sum+me[peo].two,oneme,twome+1,threeme);
	}
	if(club1==3 &&threeme<n/2+1){
		threeme++;
		jisuan(peo+1,1,sum+me[peo].three,oneme,twome,threeme+1);
		jisuan(peo+1,2,sum+me[peo].three,oneme,twome,threeme+1);
		jisuan(peo+1,3,sum+me[peo].three,oneme,twome,threeme+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long t1=0;t1<t;t1++){
		n=0;
		summax=0;
		cin>>n;
		for(long long n1=1;n1<=n;n1++){
			cin>>me[n1].one>>me[n1].two>>me[n1].three;
		}
		jisuan(0,1,0,0,0,0);
		cout<<summax<<endl;
	}
	return 0;
}
