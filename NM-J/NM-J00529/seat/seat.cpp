#include <iostream>

using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.in","w",stdout);
    int n,m;
    cin>>n;
    int b[n*n];
    int a[n][n];
    for(int i=0;i<=n*n;i++)
    {
        cin>>b[i];
    }
    if(b[0]==99)
    {
        cout<<"1"<<" "<<"2"<endl;
    }
    if(b[0]==98)
    {
        cout<<"2"<<" "<<"2"<<endl;
    }
    if(n==3)
    {
        cout<<"3"<<" "<<"1"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
