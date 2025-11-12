#include<iostream>
#include<cstdio>
#include<iomanip>
#include<math.h>
#include<queue>
#include<stack>
#include<map>
#include<cstring>
#include<vector>
#include<algorithm>
#define LL long long
const int N=1e5+10;
const int Inf=0x3f3f3f3f;
using namespace std;
LL n,a[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		for(int j=1;j<i;j++){
			for(int k=1;k<j;k++){
				for(int o=1;o<j;o++){
				if(a[j]+a[o]+a[k]>a[i]*2){
					ans++;
				}
			}
		}
	}cout<<ans;
}}

