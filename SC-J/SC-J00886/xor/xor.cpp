#include<bits/stdc++.h>
using namespace std;
const int MAXN=5*(1e5)+5;
int a[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){;
		if(a[i]==k){
			cnt++;
			a[i]=-1;
		}
	}
	for(int i=0;i<n;i++){
		int sum=a[i];
		for(int j=i+1;j<n;j++){
			if(a[j]>=0&&a[i]>=0){
				sum=a[j]^sum;			
				if(sum==k){
					cnt++;
					for(int k=i;k<=j;k++){
						a[k]=-1;
					}
				}
			}else{
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
} 