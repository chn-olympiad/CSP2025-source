#include<iostream>
using namespace std;
int n,k,num;
int a[500010];
int main (){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=a[i];
			for(int k=i+1;k<=j;k++){
				x^=a[k];
			}
			if(x==k){
				cout<<i<<" "<<j<<endl;
				num++;
				i=j;
				break;
			}
		}
	}
	cout<<num;
	return 0;
} 
