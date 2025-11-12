#include <bits/stdc++.h>

using namespace std;
const int N=1e5+1;

int* build_next(string patt)
{
    int next[N];
    int n=patt.length();
    int i=1,j=1;
    while(i<=n)
    {
        if(patt[i]==patt[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else if(j>0){
            j++;
            j=next[j];
        }
        else{
            j=next[j];
        }
    }
    return next;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)cout<<"0"<<endl;
}
