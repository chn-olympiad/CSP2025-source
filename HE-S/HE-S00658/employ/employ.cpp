#include<bits/stdc++.h>
using namespace std;
int main(){
//    freopen("employ.in","r",stdin);
//    freopen("employ.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int a=1;
    for(int i=m;i>=1;i++){
    	a*=i;
    	a=a;
	}
	cout<<a%998;
}
