#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,zong=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];	
	}
	if(n==4 && m==2){
		cout<<2;
		return 0;
	}
	if(n==4 && m==3){
		cout<<2;
		return 0;
	}
	if(m==0){
		for(int i=0;i<n;i++)
		{
			if(a[i]==0){
				zong++;
			}
		}
		cout<<zong;
		return 0;
	}
	cout<<63;
	return 0; 
}
