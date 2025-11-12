#include<bits/stdc++.h>
using namespace std;
int a[500050],n,s,b;
long long m;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		b=0;
		for(int j=i;j<n;j++){
			b=~((a[j]&b)|((~a[j])&(~b)));
			if(b==m) 
			{
				s++;
				i=j;
				break;
			}
		}
	}
	cout<<s;
}

