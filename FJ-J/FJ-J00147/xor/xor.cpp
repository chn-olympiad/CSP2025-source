#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ret=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		int temp=n-1;
		int flag=0;
		for(int j=i;j<=temp;j++)
		{
			int cnt=0;
			for(int l=j;l<=temp;l++)
			{
				cnt=cnt^a[l];
//				cout<<cnt<<' '<<a[l]<<' '<<l<<endl;
				if(cnt==k)
				{
					temp=min(temp,l);
//					cout<<l<<' '<<temp<<endl;
					flag=1;
				}
			}
//			cout<<endl;
		}
//		cout<<endl<<endl<<temp<<' '<<flag<<' '<<ret<<'!'<<endl<<endl;
		if(!flag)break;
		i=temp;
		ret++;
	}
	cout<<ret;
	return 0;
}
/*
6 2
2 1 1 3 1 3

*/
