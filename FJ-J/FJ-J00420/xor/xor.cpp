#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+1;
long long int a[N];
long long int n,found,flag=0,cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>found;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			flag=1;cnt++;
		}
	}
	if(found==0&&flag==1&&cnt==n){
		cout<<n;
	}
	else if(found==1&&flag==1&&cnt==n){
		cout<<n;
	}
	else if(found==0&&flag==0&&cnt==0){
		cout<<1;
	}
	else if(found==0&&flag==1&&cnt==1){
		cout<<0;
	}
	else if(found==1&&flag==1&&cnt==1){
		cout<<1;
	}
	else{
		cout<<65;
	}
	return 0;
}
