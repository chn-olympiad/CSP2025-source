#include<bits/stdc++.h>
using namespace std;
int n,k;
int l,r;
int h=0;
int as=0;
int a[500007];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	if(n==1&&k==0){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			h=a[i];
			for(int w=i+1;w<=j;w++){
				h=h^a[w];
			}
			if(h==k){
				i=j+1;
				j++;
				as++;
			} 
			h=0;
		}
	} 
	cout<<as;
	return 0;
} 
