#include<bits/stdc++.h>
#define int long long
using namespace std;
long long a[500010];
long long t[10];
long long n,k;
void so1(){
	long long no=a[1],sum=0;
	for(int i=2;i<=n;i++){
		if(no==k){
			no=a[i]&1;
			no=!no;
			sum++;
			continue;
		}
		no=no^a[i];
	}
	cout<<sum<<endl;
	return;
}
void so2(){
	long long no=a[1],sum=0;
	for(int i=2;i<=n;i++){
		if(no==k){
			no=a[i]&1;
			no=!no;
			sum++;
			continue;
		}
		no=no^a[i];
	}
	cout<<sum<<endl;
	return;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int f_qy1=1,f_qy2=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			t[1]++;
		}else if(a[i]==0){
			t[0]++;
		}
		if(a[i]!=1){
			f_qy1=0;
			if(a[i]!=0){
				f_qy2=0;
			}
		}
	}
	if(f_qy1){
		cout<<n/2<<endl;
		return 0;
	}else if(f_qy2){
		if(k==1){
			so1();
		}else{
			so2();
		}
		return 0;
	}
	long long no=a[1],sum=0;
	for(int i=2;i<=n;i++){
		if(no==k){
			no=a[i]&1;
			no=!no;
			sum++;
			continue;
		}
		no=no^a[i];
	}
	cout<<sum+1<<endl;
	return 0;
} 
