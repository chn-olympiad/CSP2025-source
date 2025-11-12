#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a;
int sum;
int ls;
int main()
{
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    cin>>a;
    for(int i=1;i<n*m;i++)
    {
        cin>>ls;
        if(ls>a)sum++;
    }
    int lie=sum/n+1;
    int hang=sum%n+1;
    if(!(lie&1))hang=n-hang+1;
    cout<<lie<<' '<<hang;
	return 0;
}