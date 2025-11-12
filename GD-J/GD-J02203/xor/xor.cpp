#include<bits/stdc++.h>
using namespace std;
int a[500000];
//int b[500000];
int n,k,ans=0;
//bool check1(int l,int r){
//	return b[r]+2*!b[r]-b[l]==k+2*!b[l]|k;
//}
bool check2(int l,int r){
	int cnt=a[l];
	for(int m=l+1;m<=r;m++){
		cnt^=a[m];
	}
	return cnt==k;
}
int main(){
	freopen("xor6.in","r",stdin);
	freopen("xor6.out","w",stdout);
	cin>>n>>k;
	cin>>a[0];
//	b[0]=a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
//		b[i]=b[i-1]^a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(check2(i,j)){
				ans++;
				i=j;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
