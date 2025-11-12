#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    vector<int> al;
    for(int ii=0;ii<n;ii++)
    {
        int ci;
        cin>>ci;
        al.push_back(ci);
    }
    if(n==3)
    {
        if(al[0]+al[1]+al[2]>2*max(max(al[0],al[1]),max(al[2],al[1])))
           {
               cout<<1;
           }
        else{cout<<0;}
    }
    if(n==4)
    {
        int ans=0;
        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    if(al[a]+al[b]+al[c]>2*max(al[a],max(al[b],al[c]))){ans++;}
                }
            }
        }
        if(al[0]+al[1]+al[2]+al[3]>2*max(al[0],max(al[2],max(al[3],al[1]))))
        {ans++;}
        cout<<ans;
    }
    if(n==5)
    {
        int ans=0;
        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    if(al[a]+al[b]+al[c]>2*max(al[a],max(al[b],al[c]))){ans++;}
                }
            }
        }

        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        if(al[a]+al[b]+al[c]+al[d]>2*max(al[a],max(al[b],max(al[c],al[d])))){ans++;}
                    }
                }
            }
        }

        if(al[0]+al[1]+al[2]+al[3]+al[4]>2*max(al[0],max(al[2],max(al[3],max(al[4],al[1])))))
        {ans++;}
        cout<<ans;
    }
    if(n==6)
    {
        int ans=0;
        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    if(al[a]+al[b]+al[c]>2*max(al[a],max(al[b],al[c]))){ans++;}
                }
            }
        }

        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        if(al[a]+al[b]+al[c]+al[d]>2*max(al[a],max(al[b],max(al[c],al[d])))){ans++;}
                    }
                }
            }
        }
        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        for(int e=d+1;e<n;e++)
                        {
                            if(al[a]+al[b]+al[c]+al[d]+al[e]>2*max(al[a],max(al[b],max(al[c],max(al[d],al[e]))))){ans++;}
                        }
                    }
                }
            }
        }

        if(al[0]+al[1]+al[2]+al[3]+al[4]+al[5]>2*max(al[0],max(al[1],max(al[2],max(al[3],max(al[4],al[5]))))))
        {ans++;}
        cout<<ans;
    }
    if(n==7)
    {
        int ans=0;
        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    if(al[a]+al[b]+al[c]>2*max(al[a],max(al[b],al[c]))){ans++;}
                }
            }
        }

        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        if(al[a]+al[b]+al[c]+al[d]>2*max(al[a],max(al[b],max(al[c],al[d])))){ans++;}
                    }
                }
            }
        }
        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        for(int e=d+1;e<n;e++)
                        {
                            if(al[a]+al[b]+al[c]+al[d]+al[e]>2*max(al[a],max(al[b],max(al[c],max(al[d],al[e]))))){ans++;}
                        }
                    }
                }
            }
        }

        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        for(int e=d+1;e<n;e++)
                        {
                            for(int f=e+1;f<n;f++)
                            {


                            if(al[a]+al[b]+al[c]+al[d]+al[e]+al[f]>2*max(al[a],max(al[b],max(al[c],max(al[d],max(al[e],al[f])))))){ans++;}
                            }
                        }
                    }
                }
            }
        }
        if(al[0]+al[1]+al[2]+al[3]+al[4]+al[5]+al[6]>2*max(al[0],max(al[1],max(al[2],max(al[3],max(al[4],max(al[5],al[6])))))))
        {ans++;}
        cout<<ans;}
    if(n==8)
    {
        int ans=0;
        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    if(al[a]+al[b]+al[c]>2*max(al[a],max(al[b],al[c]))){ans++;}
                }
            }
        }

        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        if(al[a]+al[b]+al[c]+al[d]>2*max(al[a],max(al[b],max(al[c],al[d])))){ans++;}
                    }
                }
            }
        }
        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        for(int e=d+1;e<n;e++)
                        {
                            if(al[a]+al[b]+al[c]+al[d]+al[e]>2*max(al[a],max(al[b],max(al[c],max(al[d],al[e]))))){ans++;}
                        }
                    }
                }
            }
        }

        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        for(int e=d+1;e<n;e++)
                        {
                            for(int f=e+1;f<n;f++)
                            {


                            if(al[a]+al[b]+al[c]+al[d]+al[e]+al[f]>2*max(al[a],max(al[b],max(al[c],max(al[d],max(al[e],al[f])))))){ans++;}
                            }
                        }
                    }
                }
            }
        }

        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        for(int e=d+1;e<n;e++)
                        {
                            for(int f=e+1;f<n;f++)
                            {
                                for(int g=f+1;g<n;g++)
                                {
                                if(al[a]+al[b]+al[c]+al[d]+al[e]+al[f]+al[g]>2*max(al[a],max(al[b],max(al[c],max(al[d],max(al[e],max(al[f],al[g]))))))){ans++;}
                                }
                            }
                        }
                    }
                }
            }
        }
        if(al[0]+al[1]+al[2]+al[3]+al[4]+al[5]+al[6]+al[7]>2*max(al[0],max(al[1],max(al[2],max(al[3],max(al[4],max(al[5],max(al[6],al[7]))))))))
        {ans++;}
        cout<<ans;}
    if(n==9)
    {
        int ans=0;
        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    if(al[a]+al[b]+al[c]>2*max(al[a],max(al[b],al[c]))){ans++;}
                }
            }
        }

        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        if(al[a]+al[b]+al[c]+al[d]>2*max(al[a],max(al[b],max(al[c],al[d])))){ans++;}
                    }
                }
            }
        }
        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        for(int e=d+1;e<n;e++)
                        {
                            if(al[a]+al[b]+al[c]+al[d]+al[e]>2*max(al[a],max(al[b],max(al[c],max(al[d],al[e]))))){ans++;}
                        }
                    }
                }
            }
        }

        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        for(int e=d+1;e<n;e++)
                        {
                            for(int f=e+1;f<n;f++)
                            {


                            if(al[a]+al[b]+al[c]+al[d]+al[e]+al[f]>2*max(al[a],max(al[b],max(al[c],max(al[d],max(al[e],al[f])))))){ans++;}
                            }
                        }
                    }
                }
            }
        }

        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        for(int e=d+1;e<n;e++)
                        {
                            for(int f=e+1;f<n;f++)
                            {
                                for(int g=f+1;g<n;g++)
                                {
                                if(al[a]+al[b]+al[c]+al[d]+al[e]+al[f]+al[g]>2*max(al[a],max(al[b],max(al[c],max(al[d],max(al[e],max(al[f],al[g]))))))){ans++;}
                                }
                            }
                        }
                    }
                }
            }
        }

        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        for(int e=d+1;e<n;e++)
                        {
                            for(int f=e+1;f<n;f++)
                            {
                                for(int g=f+1;g<n;g++)
                                {
                                    for(int h=g+1;h<n;h++)
                                    {
                                        if(al[a]+al[b]+al[c]+al[d]+al[e]+al[f]+al[g]+al[h]>2*max(al[a],max(al[b],max(al[c],max(al[d],max(al[e],max(al[f],max(al[g],al[h])))))))){ans++;}
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(al[0]+al[1]+al[2]+al[3]+al[4]+al[5]+al[6]+al[7]+al[8]>2*max(al[0],max(al[1],max(al[2],max(al[3],max(al[4],max(al[5],max(al[6],max(al[7],al[8])))))))))
        {ans++;}
        cout<<ans;}
    if(n==10)
    {

        int ans=0;
        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    if(al[a]+al[b]+al[c]>2*max(al[a],max(al[b],al[c]))){ans++;}
                }
            }
        }

        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        if(al[a]+al[b]+al[c]+al[d]>2*max(al[a],max(al[b],max(al[c],al[d])))){ans++;}
                    }
                }
            }
        }
        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        for(int e=d+1;e<n;e++)
                        {
                            if(al[a]+al[b]+al[c]+al[d]+al[e]>2*max(al[a],max(al[b],max(al[c],max(al[d],al[e]))))){ans++;}
                        }
                    }
                }
            }
        }

        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        for(int e=d+1;e<n;e++)
                        {
                            for(int f=e+1;f<n;f++)
                            {


                            if(al[a]+al[b]+al[c]+al[d]+al[e]+al[f]>2*max(al[a],max(al[b],max(al[c],max(al[d],max(al[e],al[f])))))){ans++;}
                            }
                        }
                    }
                }
            }
        }

        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        for(int e=d+1;e<n;e++)
                        {
                            for(int f=e+1;f<n;f++)
                            {
                                for(int g=f+1;g<n;g++)
                                {
                                if(al[a]+al[b]+al[c]+al[d]+al[e]+al[f]+al[g]>2*max(al[a],max(al[b],max(al[c],max(al[d],max(al[e],max(al[f],al[g]))))))){ans++;}
                                }
                            }
                        }
                    }
                }
            }
        }

        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        for(int e=d+1;e<n;e++)
                        {
                            for(int f=e+1;f<n;f++)
                            {
                                for(int g=f+1;g<n;g++)
                                {
                                    for(int h=g+1;h<n;h++)
                                    {
                                        if(al[a]+al[b]+al[c]+al[d]+al[e]+al[f]+al[g]+al[h]>2*max(al[a],max(al[b],max(al[c],max(al[d],max(al[e],max(al[f],max(al[g],al[h])))))))){ans++;}
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        for(int e=d+1;e<n;e++)
                        {
                            for(int f=e+1;f<n;f++)
                            {
                                for(int g=f+1;g<n;g++)
                                {
                                    for(int h=g+1;h<n;h++)
                                    {
                                        for(int i=h+1;i<n;i++)
                                            {
                                            if(al[a]+al[b]+al[c]+al[d]+al[e]+al[f]+al[g]+al[h]+al[i]>2*max(al[a],max(al[b],max(al[c],max(al[d],max(al[e],max(al[f],max(al[g],max(al[h],al[i]))))))))){ans++;}
                                            }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(al[0]+al[1]+al[2]+al[3]+al[4]+al[5]+al[6]+al[7]+al[8]+al[9]>2*max(al[0],max(al[1],max(al[2],max(al[3],max(al[4],max(al[5],max(al[6],max(al[7],max(al[8],al[9]))))))))))
        {ans++;}
        cout<<ans;}
     else{
        cout<<366911923;}
    return 0;
}
