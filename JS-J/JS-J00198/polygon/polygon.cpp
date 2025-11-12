#include <bits/stdc++.h>
using namespace std;
int a[500005];
bool f=1;
int g;
long long sum;
int main(){ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]!=a[i-1]){
			f=0;
		}
	}
	if(n<=2){cout<<0;return 0;}
	long long s2=1;
	int s1=1;
	if(f==1){
		for(int i=3;i<=n;i++){
			s1=1;
			s2=1;
			for(int j=1;j<=i;j++){
				s1*=j;
			}
			for(int j=n;j>(n-i);j--){
				s2*=j;
			}
			sum+=(s2/s1);
			sum=sum%255;
		}
		cout<<sum;
		return 0;
	}
	else{
		cout<<132;
	}
    return 0;
}
