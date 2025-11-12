#include<bits/stdc++.h>
using namespace std;
int countt(int n,int m){
	int sum=1;
	if(n>m)swap(n,m);
	for(int i=m-n;i<=m;i++)sum*=i;
	for(int i=2;i<=n;i++)sum/=i;
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n,cnt=0;
	cin>>n;
	for(int i=3;i<=n;i++){
		cnt+=countt(i,n);
	}
	cout<<cnt;
} 
