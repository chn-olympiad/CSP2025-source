#include<bits/stdc++.h>
using namespace std;
struct node{
    int start,last;
};
int n,sum;
int k;
int a[500010];
node point[50001000];
int l=0;
bool f(node x,node y)
{
    if(x.start==y.start) return x.last<y.last;
    return x.start<y.start;
}
int main( )
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==k)
        {
            l++;
            point[l].start=i,point[l].last=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int c_just=a[i],c_now;
        for(int j=i+1;j<=n;j++)
        {
            c_now=a[j];
            a[j]=c_just^a[j];
            c_just=c_now;
            if(a[j]==k)
            {
                l++;
                point[l].start=j-i,point[l].last=j;
            }
        }
    }
    for(int i=1;i<=l;i++)
    {
        sort(point+1,point+l+1,f);
        sum++;
        if(point[i].last<=point[i-1].last)
        {
            sum--;
            point[i-1].start=0,point[i-1].last=0;
        }
        else if(point[i].start<=point[i-1].last)
        {
            sum--;
            point[i].start=0,point[i].last=0;
        }
    }
    cout<<sum;
	return 0;
}
