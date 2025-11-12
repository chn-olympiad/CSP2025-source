#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int sum=0;
int num[N];
int main()
{	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	int s=0;
	if(m==0){
		for(int i=0;i<n;i++){
			if(num[i]==m) sum++;
		}
		cout<<sum;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(num[i]==m){
			sum++;
		}
	}
	int a=0;
	for(int i=0;i<n-1;i++){
		if(num[i]==m) continue;
		a=num[i];
		for(int j=i+1;j<n;j++){
			if(num[j]==m) continue;
			a=(a^num[j]);
			if(a==m){
				sum++;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}

