#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,m,a[maxn],sum=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
            cin>>a[i];
            if(a[i]>a[1])sum++;
    }
    int l=1,r=1;
    while(sum--)
    {
        if(l%2==0)
            r--;
        else
            r++;
        if(r>n&&l%2==0||r<1&&l%2==0)
        {
            l++;
            r=1;
        }
        else if(r>n&&l%2==1||r<1&&l%2==1)
        {
            l++;
            r=n;
        }
    }
    cout<<l<<' '<<r;
	return 0;
}
