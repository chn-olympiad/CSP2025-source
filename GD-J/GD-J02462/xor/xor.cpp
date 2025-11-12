#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,a[N];
bool e[23];//e[i]=1表示第i位为 1 
int ans=0;
int p,dq;
bool check(){
	return (dq==k);
}
void fuzhi(){
	p=dq;
}
void huan(){
	dq=p;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int wz=1;
	for(int i=1;i<=n;i++){
		dq^=a[i];
		if(check()){
			wz=i+1;
			ans++;
			dq=0;
		}
		else{
			bool flag=0;
			fuzhi();
			for(int j=wz;j<i;j++){
				dq^=a[j];
				if(check()){
					flag=1;
					dq=0;
					wz=i+1;
					ans++;
					break;
				}
			}
			if(flag==0)huan();
		}
	}
	cout<<ans;
}
