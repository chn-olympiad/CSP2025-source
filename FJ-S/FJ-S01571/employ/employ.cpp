#include <bits/stdc++.h>
using namespace std;
long long n,m,mm;
string Q;
long long c=0,l,by;
long long a[100001],b[10001];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>Q;
	for(int i=1;i<=n;i++){
		b[1]=i%10;
		b[2]=i/10%10;
		b[3]=i/100%10;
		if(b[3]){
			mm=3;
		}
		else if(b[2]){
			mm=2;
		}
		else{
			mm=1;
		}
		for(int j=1;j<=mm;j++){
			for(int k=1;k<=n;k++){
				if(a[k]*b[j]+by>10){
					a[k]=(a[k]*b[j]+by)%10;
					by=(a[k]*b[j]+by)/10;
				}
				else{
					a[k]=a[k]*b[j]+by;
				} 
			} 
		}
		if(by){
			l=n+1;
			while(by){
				a[l]=by%10;
				by/=10;
				l++;
			}
		}
	}
	l=0;
	for(int i=1;i<=9;i++){
		c+=a[i]*pow(10,l);
		l++;
	}
	cout<<0;
	return 0;
}
