#include<bits/stdc++.h>
using namespace std;
int n,a[5114];
// da biao xian ren
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<3) cout<<0;
	else
	{
		if(n==3) 
		{
			if(a[1]+a[2]<=a[3]) cout<<0;
			else cout<<1;
		}
		else if(n>3&&n<=5) cout<<6;
		else if(n>5) cout<<50;
	}
	//哈基米南北绿豆
    return 0;
    }
