#include<bits/stdc++.h>
bool cmp(int a,int b){
    return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,s[120],sl=0;
    std::cin>>n>>m;
    std::cin>>s[0];
    int nf=s[0];
    for(int i=1;i<n*m;i++){
        std::scanf("%d",&s[i]);
    }
    std::sort(s,s+n*m,cmp);
    int a[12][12]={0};
    for(int j=1;j<=m;j++){
        if(j%2!=0){
            for(int i=1;i<=n;i++){
                a[i][j]=s[sl];
                sl++;
            }
        }
        else{
            for(int i=n;i>=1;i--){
                a[i][j]=s[sl];
                sl++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==nf){
				std::printf("%d %d",j,i);
			}
        }
    }
    return 0;
}
