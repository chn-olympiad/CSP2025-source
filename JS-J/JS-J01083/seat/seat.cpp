#include<bits/stdc++.h>
using namespace std;
long long m,n,num=1;
long long a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    for(long long i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			num+=1;
		}
    }
    long long h=num%m;
    long long s=num/m;
    if(s%2==1){
		cout<<h+1<<' '<<s+1;
    }else{
		cout<<m-h+2<<' '<<s+1;
    }
	return 0;
}
