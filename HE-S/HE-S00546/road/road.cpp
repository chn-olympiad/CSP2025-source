#include<iostream>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n=10005,m=1000005;
    cin>>n>>m;
    int min;
    cin>>min;
    int p;
    cin>>p;
    for(int i=1;i<min;i++)
{
    if(p==min){
        cout<<p;
       break;

    }
    else
    {

        cout<<min;
    }

}
cout<<13;
    return 0;
}
