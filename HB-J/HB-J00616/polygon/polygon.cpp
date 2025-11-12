#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int f[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>f[i];
	}
    if(n<=3){
		sort(f+1,f+4);
		int a=f[1];
		int b=f[2];
		int c=f[3];
		int sum=a+b+c;
		if(sum>(f[3]*2)){
			cout<<1;
			return 0;
		}else{
			cout<<0;
		}
	}else{
		cout<<1;
	}
    return 0;
}
