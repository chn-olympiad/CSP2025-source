#include<bits/stdc++.h>
using namespace std;
int n,t,a[1000][5],p,o[3],sum=0,maxn;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        for(int j=0;j<t;j++){
            cin>>a[j][0];
            cin>>a[j][1];
            cin>>a[j][2];
        }
		maxn=-1;
		for(int k=0;k<3;k++){
			if(a[k]>maxn || (a[k]==maxn && o[k]<=o[p])){
				maxn=a[k];
				p=k;
				o[k]++;
				sum=sum+a[k];
			}
		}
    }
    cout<<sum;
	return 0;
}
