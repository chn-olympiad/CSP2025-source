#include <bits/stdc++.h>
using namespace std;
struct A{
	long long int m1;
	long long int m2;
	long long int m3;
	int q=1;
};
long long int t,n,res;
A a[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		long long int aa=n/2;
		long long int b[3]={aa,aa,aa};
		for(int j=0;j<n;j++){
			cin>>a[j].m1>>a[j].m2>>a[j].m3;
		}
		for(int j=0;j<n;j++){
			if(a[j].m1>a[j].m2&&a[j].m1>a[j].m3&&b[0]!=0){
				res+=a[j].m1;
				b[0]--;
			}else if(a[j].m2>a[j].m1&&a[j].m2>a[j].m3&&b[0]!=1){
				res+=a[j].m2;
				b[1]--;
			}else {
				res+=a[j].m3;
				b[2]--;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
} 
