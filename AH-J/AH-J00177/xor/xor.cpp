#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,t,sum,maxn=0,a[700000],sumn=0;
	bool flag[700000],flag2;
	memset(flag,false,sizeof(flag));
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			flag2=true;
			sum=a[j];
			if(flag[j]){
				flag2=false;
				continue;
			}
			for(int k=j+1;k<=j+i-1;k++){
				sum=sum^a[k];
				if(flag[k]){
					flag2=false;
					break;
}
			}
            if(sum==t&&flag2){
			maxn=max(maxn,i);
			sumn++;
			for(int k=j;k<=j+i-1;k++){
				flag[k]=true;
			}
		}	
		}
		}
	cout<<sumn<<endl;
	return 0;
}
