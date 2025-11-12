#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<=n;){
		for(int j=i;j<=n;j++){
			char pan=1;
			if(i==j and a[i]==k){
				sum++;
				i+=j;
				pan=0;
			}
			else{
				int a1=a[i],b1=a[i+1];
				int ans = (a1 xor b1);
				for(int g=i+2;g<=j;g++){;
					ans = (ans xor a[g]);
				}
				if(ans == k){
					sum++;
					i+=j;
					pan=0;
				}
				if(pan){
					i++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
