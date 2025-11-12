#include<bits/stdc++.h>
    using namespace std;
    int a[100010][5],d1[100010],d2[100010],d3[100010];
    long long k[25];
    int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,p=0;
    cin>>t;
    while(t--){
		memset(d1,0,sizeof(d1));
		memset(d2,0,sizeof(d2));
		memset(d3,0,sizeof(d3));
    int n,s1=0,s2=0,s3=0;
    long long s=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
    if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
    s1++;
    d1[i]=a[i][1]-max(a[i][2],a[i][3]);
    }
    else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
    s2++;
    d2[i]=a[i][2]-max(a[i][1],a[i][3]);
    }
    else if(a[i][3]>a[i][2]&&a[i][3]>a[i][1]){
    s3++;
    d3[i]=a[i][3]-max(a[i][1],a[i][2]);
    }
    s+=max(a[i][1],max(a[i][2],a[i][3]));
    }
    if(s1<=n/2&&s2<=n/2&&s3<=n/2){
    k[++p]=s;
    }
    else{
    if(s1>n/2){
    sort(d1+1,d1+n+1);
    for(int i=1;i<=n/2;i++)s-=d1[i];
    }
    else if(s2>n/2){
    sort(d2+1,d2+n+1);
    for(int i=1;i<=n/2;i++)s-=d2[i];
    }
    else if(s3>n/2){
    sort(d3+1,d3+n+1);
    for(int i=1;i<=n/2;i++)s-=d3[i];
    }
    k[++p]=s;
    }
    }
    for(int i=1;i<=p;i++){
		cout<<k[i]<<endl;
	}
    return 0;
    }
