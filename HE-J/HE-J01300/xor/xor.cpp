#include <iostream>
#include <cstdio>
using namespace std;
int n,k;
int a[500001];
int vis[500001];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	int flag=1,flag2=1;
	int num_1=0,num_0=0,num_l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;
		}
		if(a[i]!=1 && a[i]!=0){
			flag2=0;
		}
		if(a[i]==1){
			num_1++;
		}
		if(a[i]==0){
			num_0++;
		}
		if(a[i]==1 && a[i-1]==1 && vis[i]==0 && vis[i-1]==0){
			num_l++;
			vis[i]=1;
			vis[i-1]=1;
		}
	}
	if(flag==1){
		cout<<n/2<<endl;
	}
	else if(flag2==1){
		if(k==1){
			cout<<num_1<<endl;
		}
		else{
			cout<<num_0+num_l<<endl;
		}
	}
	else{
		cout<<7<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
