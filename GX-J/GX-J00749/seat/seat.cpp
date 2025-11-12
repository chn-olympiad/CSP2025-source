#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
bool p(int a,int b)
{
	if(a>=b)return 1;
	return 0;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[300];
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    int qu=a[0];
    sort(a,a+n*m);
    int l=1,h=1,kk=1,f=0;
    for(int i=0;i<n*m;i++)
    {
        if(a[i]!=qu)
        {
            if((h==n||h==1)&&l!=1&&f==1)
            {
                kk*=-1;
                f=0;
                l++;
            }
            else {h+=kk;f=1}
        }
        if(a[i]==qu)
        {
            cout<<l<<" "<<h;
            fclose(stdin);
            fclose(stdout);
            return 0;   }

    }

}
