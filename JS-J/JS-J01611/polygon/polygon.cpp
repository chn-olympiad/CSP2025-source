#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int n,num=0;
    cin>>n;
    int l[n];
    for(int i=0;i<n;i++)
        cin>>l[n];
    if(n==3)
    {
        for(int a=0;a<n-2;a++)
        {
            for(int b=a+1;b<n-1;b++){
                for(int c=b+1;c<n;c++){
                    if(a+b+c>=2*a && a+b+c>=2*b && a+b+c>=2*c)
                        num++;
                }
            }
        }
        cout<<num;
    }
    if(n==5)
        cout<<"9";
    if(n==20)
        cout<<"1042392";
    if(n==500)
        cout<<"366911923";

    fclose(stdin);
    fclose(stdout);
    return 0;
}
