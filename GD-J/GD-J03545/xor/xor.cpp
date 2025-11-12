#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	int n,k;
	cin>>n>>k;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			num++;
		}
	}
	if(k==0){
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				num++;
				i++;
			}
		}
	}
	cout<<num;
	return 0;
}
