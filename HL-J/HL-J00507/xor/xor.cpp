#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,m;
	long long a[100010],flag[100010]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(j==i and a[i]==m and flag[i]==0){
				flag[i]=1;
				sum++;
			}
			else{
				int f=1;
				for(int b=i;b<=j;b++){
					if(flag[b]==1){
						f=0;
						break;
					}
				}
				int cnt=a[i];
				for(int b=i+1;b<=j;b++){
					flag[b]=1;
					cnt=cnt^a[b];
				}
				if(cnt==m and f){
					sum++;
				}
			}
		}
	}
	cout<<sum+1;
}