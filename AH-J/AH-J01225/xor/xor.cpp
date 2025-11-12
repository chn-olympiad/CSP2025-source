#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k){
		int num=0;
		for(int i=1;i<=n;i++){
			if(a[i])num++;
		}
		cout<<num;
	}
	else{
		int num=0;
		for(int i=1;i<=n;i++){
			if(a[i]){
				if(a[i+1]){
					num++;
					i++;
				}
			}
			else num++;
		}
		cout<<num;
	}
	return 0;
}
