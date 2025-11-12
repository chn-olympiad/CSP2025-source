#include <iostream>

using namespace std;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
    long long ans=0;
    int k;
    long long n,m;
    cin>>n>>m>>k;
    int M[m],a[m],b[m];
    int c[n];
    int cm[n][m];
    for(int i=0;i<m;i++){

        cin>>a[i]>>b[i];
        cin>>M[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
        for(int j=0;j<n;j++){
            cin>>cm[i][j];
            ans+=cm[i][j];
            M[j]=0;

        }
    }
    for(int i=0;i<m;i++){
        ans+=a[m];
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
