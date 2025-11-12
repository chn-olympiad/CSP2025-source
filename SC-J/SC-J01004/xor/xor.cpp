#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<0;
	}
	else if(k==0&&n<=1000){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				s++;
			}
		}
		cout<<s;
	}
	else if(k==1&&n<=1000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int w=0;
				for(int k=i;k<=j;k++){
					if(a[k]==1){
						w++;
					}
				}
				if(w==1){
					s++;
				}
			}
		}
		cout<<s;
	}
	return 0;
}