#include<bits/stdc++.h>
using namespace std;
int n,k,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	vector<int>a(n+5);
	vector<bool>b(n+5,false);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			b[i]=true;
			sum++;
		}
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			int num=a[i];
			if(num==1)num=2;
			for(int j=i+1;j<=n&&!b[j];j++){
				if(num==1)num=2;
				num|=a[j];
				if(num==k){
					sum++;
					i=j+1;
					break;
				}
			}
		}
	}
	cout<<sum;
	return 0;
} 
