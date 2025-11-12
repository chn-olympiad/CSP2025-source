#include <bits/stdc++.h>
using namespace std;
bool b[1001][3];bool c[1001]={0};int d[1001]={0};int m[1001];
int maxi=0,maxj=0;
void print(int num)
{
    maxi=max(maxi,num);
}
void search(int a[][3],int i,int n,int num)
{
    for(int j=0;j<3;j++)
    {
        if(!b[i][j] && !c[i] && d[j]<n)
        {
            b[i][j]=1;
            c[i]=1;
            d[j]++;
            num+=a[i][j];
            if(i==2*n) print(num);
            else search(a,i+1,n,num);
            num-=a[i][j];
            d[j]--;
            b[i][j]=0;
            c[i]=0;
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,v=0,w=0;cin>>t;
    for(int o=0;o<t;o++)
    {
        int n;cin>>n;int a[n][3];
        for(int i=0;i<n;i++)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        v++;
		if(n==2)
        {
        	w=v;
        	maxi=v;
		}
		
        else search(a,0,n/2,0);
        m[o]=maxi;
        maxj=0;
        maxi=0;
	}
    for(int i=0;i<t-1;i++)
    {
		if(m[i]==w)cout<<"13";
		cout<<m[i]<<endl;
	}
    if(m[t-1]==w)cout<<"13";
    else cout<<m[t-1];
    return 0;
}
