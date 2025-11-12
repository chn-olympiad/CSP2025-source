#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n;
	int m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    int k=0;
    for(int i=1;i<n*m;i++)
    {
        if(a[i]>a[0])
            k++;
    }
    int c=k/n+1,r;
    if(c%2==1)
        r=k%n+1;
    else
        r=n-k%n;
    cout<<c<<' '<<r;
	return 0;
}
