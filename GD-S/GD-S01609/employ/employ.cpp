#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+2;
unsigned int a[MAXN],n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//cout<<1<<" ";
	int flag=2;
	//a[1]=-1;
	for(int i=1;i<=n;i++){
		if(a[i]!=-1){
			cout<<i<<" ";
			flag=a[i];
			a[i]=-1;
		}
		for(int j=i+1;j<=n;j++){
			if(a[j]!=flag&&a[j]!=-1){
			cout<<j<<" ";
			flag=a[j];
			a[j]=-1;
			}
		}
		cout<<endl;
	}
}
