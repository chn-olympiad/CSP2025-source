#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=n*m;
	int sum=0;
	int a[cnt+5];
	for(int i=1;i<=cnt;i++){
		cin>>a[i];
		sum=a[1];
	}
	int cpp=0,cpd=0;
	sort(a+1,a+cnt+2,cmp);
	for(int i=1;i<=cnt;i++){
		if(a[i]==sum){
			cpp=i,cpd=i;
			if(cpd<=n){
			cpd=1;
			cout<<cpd<<" "<<cpp;
			return 0;
			}
			else if(cpd>n){
			cpd=cpd/n+1;
			cout<<cpd<<" ";
			if(cpd%2!=0){
				if(cpp%n==n){
				cout<<n;
				return 0;
				}
				else if(cpp%n!=n){
				cpp=cpp-(cpd-1)*n;
				cout<<cpp;
				return 0;
				}
			}
			else if(cpd%2==0){
				cpp=n-cpp%n+1;
				cout<<cpp;
			}
			}
		}
	}
	return 0;
}
