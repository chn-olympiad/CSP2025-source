#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long a,b,c,sum = 0,sum1 = 0,flag;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
//	for(long long i = 1;i <= a;++i){
//		cin>>b;
//		c[i] = b;
//	}
	cin>>a>>b>>c;
//	for(long long i = 1;i <= a;++i){
//		for(long long j = i;j < a;++j){
//			sum += c[j];
//			if(sum > c[a]){
//				sum1++;
//			}
//		}
//		for(long long j = i;j < a;++j){
//			sum -= c[j];
//			if(sum > c[a]){
//				sum1++;
//			}
//			sum += c[j];
//		}
//	}
	if(a + b + c >= max(max(a,b),c)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
