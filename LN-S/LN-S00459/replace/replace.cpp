#include <iostream>

using namespace std;

struct node
{
    int a,b,c;
    int huo;
}stu[100001];
int liuq(int a,int b)
{
    if(a > b)
        return a - b;
    return b - a;
}
struct zui
{
    int yuan;
    int value;
    int max2;
    int p;
}max1[100001],max3[100001];
int main()
{
  freopen("club2.in","r",stdin);
 freopen("club2.ans","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,pj[4],l = 1;
        pj[1] = 0;
        pj[2] = 0;
        pj[3] = 0;
        long long sum = 0;
        int w = 0;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
        {//find max & cha max

            scanf("%d%d%d",&stu[i].a,&stu[i].b,&stu[i].c);
            stu[i].huo = 0;
            max1[i].yuan = i;
            max1[i].value = liuq(stu[i].a,stu[i].b);
            if(stu[i].a >= stu[i].b)
            {
                max1[i].max2 = stu[i].a;
                max1[i].p = 1;
            }
            else
            {
                max1[i].max2 = stu[i].b;
                max1[i].p = 2;
            }
            if(max1[i].value < liuq(stu[i].b,stu[i].c))
            {
                if(stu[i].b >= stu[i].c)
                {
                    max1[i].max2 = stu[i].b;
                    max1[i].p = 2;
                }
                else
                {
                    max1[i].max2 = stu[i].c;
                    max1[i].p = 3;
                }
            }
            if(max1[i].value < liuq(stu[i].a,stu[i].c))
            {
                if(stu[i].a >= stu[i].c)
                {
                    max1[i].max2 = stu[i].a;
                    max1[i].p = 1;
                }
                else
                {
                    max1[i].max2 = stu[i].c;
                    max1[i].p = 3;
                }
            }
            for(int j = i;j >= 2;j--)
            {
                if(max1[j].value > max1[j - 1].value||max1[j].value == max1[j - 1].value&&max1[j].max2 > max1[j - 1].max2)
                {
                    swap(max1[j],max1[j - 1]);
                }
            }
        }
        for(int i = 1;i <= n;i++)
        {
            if(pj[max1[i].p]==n/2)
            {
                w = max1[i].p;
                break;
            }
            if((pj[max1[i].p]+1) <= (n / 2))
            {
                sum += max1[i].max2;
                pj[max1[i].p]++;
                stu[max1[i].yuan].huo = -1;
            }

        }
        if(w)
        {
            if(pj[w] == 1)
            {
                for(int j = 1;j <= n;j++)
                {
                    stu[j].a = -1;
                }
            }
            if(pj[w] == 2)
            {
                for(int j = 1;j <= n;j++)
                {
                    stu[j].b = -1;
                }
            }
            if(pj[w] == 3)
            {
                for(int j = 1;j <= n;j++)
                {
                    stu[j].c = -1;
                }
            }
            for(int j = 1;j <= n;j++)
            {
                if(stu[j].huo != -1)
                {
                    if(w == 1)
                    {
                        max3[l].value = liuq(stu[j].b,stu[j].c);
                        if(stu[j].b >= stu[j].c)
                        {
                            max3[l].max2 = stu[j].b;
                            max3[l].p = 2;
                        }
                        else
                        {
                            max3[l].max2 = stu[l].c;
                            max3[l].p = 3;
                        }
                        l++;
                    }
                    if(w == 2)
                    {
                        max3[l].value = liuq(stu[j].a,stu[j].c);
                        if(stu[j].a >= stu[j].c)
                        {
                            max3[l].max2 = stu[j].a;
                            max3[l].p = 1;
                        }
                        else
                        {
                            max3[l].max2 = stu[l].c;
                            max3[l].p = 3;
                        }
                        l++;
                    }
                    if(w == 3)
                    {
                        max3[l].value = liuq(stu[j].a,stu[j].b);
                        if(stu[j].a >= stu[j].b)
                        {
                            max3[l].max2 = stu[j].a;
                            max3[l].p = 1;
                        }
                        else
                        {
                            max3[l].max2 = stu[l].b;
                            max3[l].p = 2;
                        }
                        l++;
                    }
                    for(int k = j;k >= 2;k--)
                    {
                        if(max3[k].value >max3[k - 1].value||max3[k].value == max3[k].value&&max3[k].max2 > max3[k-1].max2)
                        {
                            swap(max3[k],max3[k - 1]);
                        }
                    }
                }
            }
            w = 0;
            for(int i = 1;i <= (l-1);i++)
            {
                if(pj[max3[i].p] == n/2)
                {
                    w = max3[i].p;
                    cout<<w;
                    break;
                }
                if((pj[max3[i].p] + 1) <= (n/2))
                {
                    sum+=max3[i].max2;
                    stu[max3[i].yuan].huo = -1;
                    pj[max3[i].p]++;
                }
            }
            if(w)
            {
                if(w == 1)
                {
                    for(int i = 1;i <= n;i++)
                    {
                        if(stu[i].huo != -1)
                        {
                            if(stu[i].b != -1)
                                sum+=stu[i].b;
                            if(stu[i].c != -1)
                                sum+=stu[i].c;
                        }
                    }
                }
                if(w == 2)
                {
                    for(int i = 1;i <= n;i++)
                    {
                        if(stu[i].huo != -1)
                        {
                            if(stu[i].a != -1)
                                sum+=stu[i].a;
                            if(stu[i].c != -1)
                                sum+=stu[i].c;
                        }
                    }
                }
                if(w == 3)
                {
                    for(int i = 1;i <= n;i++)
                    {
                        if(stu[i].huo != -1)
                        {
                            if(stu[i].a != -1)
                                sum+=stu[i].a;
                            if(stu[i].b != -1)
                                sum+=stu[i].b;
                        }
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//Ren5Jie4Di4Ling5%
// 6 7 8
// 1 3 10
// 2 5 6
// 2 5 1
// xianzhao chamax,zaizheng
//cha == namexuanrenzuishaode
//6 2 3
//7 1 5
//cha min de max
// 100 80 1
// 10 2 1
