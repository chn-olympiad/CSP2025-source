#include<bits/stdc++.h>
using namespace std;
int pros[100100];
//int roam[100100];
//bool valid[100100]={0};
struct valid1
{
    int lef;
    int rit;
    int len;
    int val=0;
}valid[100100];
int exor(int l,int r)
{
    int ans=pros[l];
    for (int i=l+1;i<=r;i++)
        ans=ans^pros[i];
    return ans;
}//checked
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,allval=-1;
    cin>>n>>k;
//    memset(roam,0x7f,sizeof(roam));
    for (int i=0;i<n;i++)
        cin>>pros[i];
    for (int i=0;i<n;i++)
        for (int j=i;j<n;j++)
    {
        if (exor(i,j)==k)
        {
            //cout<<i<<" "<<j<<endl;
            valid[++allval].lef=i;
            valid[allval].rit=j;
            valid[allval].len=j-i;
            valid[allval].val=1;
            for (int d=0;d<allval;d++)
            {
                if ((valid[d].rit>=i&&valid[d].rit<=j)||(valid[d].lef<=j&&valid[d].lef>=i)||(valid[d].lef>=i&&valid[d].rit<=j)||(valid[d].lef<=i&&valid[d].rit>=j))
                {
                    //cout<<"might be invalid!\n";
                    if(valid[d].val&&valid[d].len<j-i)
                        {
                            valid[allval].val=0;
                            valid[d].val=1;
                            //cout<<"invalid"<<allval<<endl;
                        }
                    if(valid[d].val&&valid[d].len>=j-i)
                        {
                            valid[allval].val=1;
                            valid[d].val=0;
                            //cout<<"invalid"<<d<<endl;
                        }
                }
                //if (roam[d]!=0x7f&&j-i<roam[d]&&valid[d])
            }

        }

    }
    int ans=0;
    for (int z=0;z<=allval;z++)
        if(valid[z].val==1)
            ans++;
        cout<<ans;
    return 0;
}
