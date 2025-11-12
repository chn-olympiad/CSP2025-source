#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int x,k=0;
    cin>>x;
    for(int i=2;i<=n*m;i++){
        int tmp;
        cin>>tmp;
        if(tmp>x) k++;
    }
    int i=1,j=1;
    while(k!=0){
        if(i%n==0 && j%2==1) j++;
        else if(i%n==0 && j%2==0) i--;
        else if(i==1 && j%2==0) j++;
        else if(j%2==0) i--;
        else if(j%2==1) i++;
        k--;
    }
    cout<<j<<" "<<i<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
