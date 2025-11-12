#include<bits/stdc++.h>
using namespace std;
struct member
{
    int id,cha,chacha,idx2,num;
};
const int MAXN=1e5+10;
int a[MAXN][5];
member grop1[MAXN];
member grop2[MAXN];
member grop3[MAXN];
int len1=1,len2=1,len3=1;
void printgrop()
{
    cout<<"group1:"<<endl;
    for(int i=1;i<len1;i++)
    {
        cout<<"member"<<i<<":"<<grop1[i].id<<" "<<grop1[i].cha<<" "<<grop1[i].idx2<<endl;
    }
    cout<<endl;
    cout<<"group2:"<<endl;
    for(int i=1;i<len2;i++)
    {
        cout<<"member"<<i<<":"<<grop2[i].id<<" "<<grop2[i].cha<<" "<<grop2[i].idx2<<endl;
    }
    cout<<endl;
    cout<<"group3:"<<endl;
    for(int i=1;i<len3;i++)
    {
        cout<<"member"<<i<<":"<<grop3[i].id<<" "<<grop3[i].cha<<" "<<grop3[i].idx2<<endl;
    }
    cout<<endl;
    return ;
}
int getsum()
{
    int sum=0;
    for(int i=1;i<len1;i++)
    {
        sum+=grop1[i].num;
    }
    for(int i=1;i<len2;i++)
    {
        sum+=grop2[i].num;
    }
    for(int i=1;i<len3;i++)
    {
        sum+=grop3[i].num;
    }
    return sum;
}
bool cmp(member a,member b)
{
    if(a.cha==b.cha)
    {
        return a.chacha<b.chacha;
    }
    return a.cha<b.cha;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        len1=1;
        len2=1;
        len3=1;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int mx=-1;
            int idx1=-1;
            int idx2=-1;
            int mx2=-1;
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
                if(mx<a[i][j])
                {
                    mx=a[i][j];
                    idx1=j;
                }
            }
            for(int j=1;j<=3;j++)
            {
                if(mx2<a[i][j] && j!=idx1)
                {
                    mx2=a[i][j];
                    idx2=j;
                }
            }
            member mmm;
            mmm.num=a[i][idx1];
            mmm.id=i;
            mmm.chacha=a[i][idx1]-a[i][6-idx1-idx2];
            mmm.cha=a[i][idx1]-a[i][idx2];
            mmm.idx2=idx2;
            if(idx1==1)
            {
                grop1[len1]=mmm;
                len1++;
            }
            else if(idx1==2)
            {
                grop2[len2]=mmm;
                len2++;
            }
            else
            {
                grop3[len3]=mmm;
                len3++;
            }
        }
        //printgrop();
        int ans=getsum();
        //cout<<ans<<endl;
        int len[5];
        len[1]=len1;
        len[2]=len2;
        len[3]=len3;
        if(len1-1>n/2)
        {
            //cout<<"in1"<<endl;
            sort(grop1,grop1+len1-1,cmp);
            int surplus=len1-(n/2)-1;
            int sup[5];
            sup[1]=0;
            sup[2]=0;
            sup[3]=0;
            for(int i=1;i<=surplus;i++)
            {
                sup[grop1[i].idx2]++;

                if(sup[grop1[i].idx2]+len[grop1[i].idx2]-1>n/2)
                {
                    //cout<<sup[grop1[i].idx2]<<" "<<len[grop1[i].idx2]<<endl;
                    //cout<<"in11"<<endl;
                    ans-=grop1[i].chacha;
                }
                ans-=grop1[i].cha;
            }
        }
        else if(len2-1>n/2)
        {
            //cout<<"in2"<<endl;

            sort(grop2,grop2+len2,cmp);
            int surplus=len2-(n/2)-1;
            int sup[5];
            sup[1]=0;
            sup[2]=0;
            sup[3]=0;
            //cout<<surplus<<endl;
            for(int i=1;i<=surplus;i++)
            {
                sup[grop2[i].idx2]++;
                //cout<<sup[grop2[i].idx2]<<" "<<len[grop2[i].idx2]-1<<endl;
                if(sup[grop2[i].idx2]+len[grop2[i].idx2]-1>n/2)
                {

                    //cout<<"in21"<<endl;
                    ans-=grop2[i].chacha;
                }
                //cout<<grop2[i].cha<<endl;
                ans-=grop2[i].cha;
            }
        }
        else if(len3-1>n/2)
        {
            //cout<<"in3"<<endl;
            sort(grop3,grop3+len3-1,cmp);
            int surplus=len3-(n/2)-1;
            //cout<<surplus<<endl;
            int sup[5];
            sup[1]=0;
            sup[2]=0;
            sup[3]=0;
            for(int i=1;i<=surplus;i++)
            {
                sup[grop3[i].idx2]++;
                if(sup[grop3[i].idx2]+len[grop3[i].idx2]-1>n/2)
                {
                    ans-=grop3[i].chacha;
                }
                //cout<<grop3[i].cha<<endl;
                ans-=grop3[i].cha;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}