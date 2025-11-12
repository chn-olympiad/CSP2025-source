#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,k;
int l=-1,g=-1;
int sum=0,sum1=0;
int a[N];
int b[N];
int i,j;
int dfs(int x,int y){
	int k1;
	int cnt=x;
	for(k1=x;k1<y;k1++){
//		cout<<"cntÇ°:"<<cnt<<" ";
		cnt^=b[k1+1];
//		cout<<"cntÖĞ:"<<cnt<<endl;
	}
//	cout<<"cntºó:"<<cnt<<endl;
	return cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	if(k==0){
		for(i=0;i<n;i++){
			if(a[i]==0){
				sum=1;
				break;
			}
		}
		if(sum==0){
			cout<<0;
			return 0;
		}
	}
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
//			sum=0;
			if((i<l&&j<l)||(i>g&&j>g)){
				sum=dfs(a[i],a[j]);
//				cout<<"sum:"<<sum<<" ";
				if(sum==k){
					l=i,g=j;
					sum1++;
//					cout<<endl<<i<<" "<<j<<endl;
				}
			}
			
		}
	}
	cout<<sum1;
	return 0;
}

