#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    vector<int> vi;
    cin>>n>>k;
    int linshi;
    for(int i=0;i<n;i++)
    {
        cin>>linshi;
        vi.push_back(linshi);
    }
    if(vi.size()>=k)
    {
        cout<<vi.size()-k+1;
    }
    else
    {
        cout<<1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
