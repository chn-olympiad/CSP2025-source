#include<bits/stdc++.h>
using namespace std;
long long o;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>o;
    while(o!=0){
		a[o%10]++;
		o/=10;
		}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
			}
		}
    return 0;
}
