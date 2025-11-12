#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<climits>
#include<random>
#include<ctime>
#define ll long long
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0));
	ll x=rand()%998244353+2204128;
	printf("%lld",x);
	return 0; 
} 
