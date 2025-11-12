#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in ","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,num=0,a=0,p[5005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=;j++){
			for(int k=j+1;k<=;k++){
				if(p[i]+p[j]>p[k] || p[i]+p[k]>p[j] || p[j]+p[k]>p[i]){
					num++;
				}
			}
		}
	}
	cout<<num;
	return 0;
}
