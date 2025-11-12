#include<bits/stdc++.h>
using namespace std;
int a[500020];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s=-1;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(s==-1){
			s=a[i];
		}else{
			s=s^a[i];
		}
		if(a[i]==k){
			s=-1;
			sum++;
		}	
	}
	cout<<sum<<endl;
	return 0;
}
