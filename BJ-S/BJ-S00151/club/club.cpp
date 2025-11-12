#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct score
{
    int part;//部门
    ll num;//对该部门的满意度
};

struct member
{
    score st;//满意度最高的
    score nd;//满意度第二高的
    score rd;//满意度第三高的
};

bool cmp_club(member a,member b)
{
    return (a.st.num-a.nd.num) < (b.st.num-b.nd.num);
}

bool cmp(score a,score b)
{
    return a.num > b.num;
}

member c1[100001] = {},c2[100001] = {},c3[100001] = {};//部门人员

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t = 0;
    cin >> t;
    for(int qq = 0; qq < t; qq++)
    {
        int sc1 = 0,sc2 = 0,sc3 = 0;//部门人数
        ll sum = 0;//满意度总和

        int n = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            score a[3] = {};//临时
            a[0].part = 1,a[1].part = 2;a[2].part = 3;
            cin >> a[0].num >> a[1].num >> a[2].num;
            sort(a,a+3,cmp);
            sum += a[0].num;
            if(a[0].part == 1)//加入部门一
            {
                c1[i].st = a[0];
                c1[i].nd = a[1];
                c1[i].rd = a[2];
                sc1++;
            }
            else if(a[0].part == 2)//加入部门二
            {
                c2[i].st = a[0];
                c2[i].nd = a[1];
                c2[i].rd = a[2];
                sc2++;
            }
            else if(a[0].part == 3)//加入部门三
            {
                c3[i].st = a[0];
                c3[i].nd = a[1];
                c3[i].rd = a[2];
                sc3++;
            }

        }
        /*for(int i = 1; i <= sc1; i++)
        {
            cout << c1[i].st.part << "part:" << c1[i].st.num << endl;
            cout << c1[i].nd.part << "part:" << c1[i].nd.num << endl;
            cout << c1[i].rd.part << "part:" << c1[i].rd.num << endl << endl;
        }
        for(int i = 1; i <= sc2; i++)
        {
            cout << c2[i].st.part << "part:" << c2[i].st.num << endl;
            cout << c2[i].nd.part << "part:" << c2[i].nd.num << endl;
            cout << c2[i].rd.part << "part:" << c2[i].rd.num << endl << endl;
        }
        for(int i = 1; i <= sc3; i++)
        {
            cout << c3[i].st.part << "part:" << c3[i].st.num << endl;
            cout << c3[i].nd.part << "part:" << c3[i].nd.num << endl;
            cout << c3[i].rd.part << "part:" << c3[i].rd.num << endl;
        }
        */

        int limit = n/2;
        int d1 = limit-sc1,d2 = limit-sc2,d3 = limit-sc3;

        if(d1<0)
        {
            sort(c1,c1+sc1,cmp_club);//按第二高降序排列
            for(int i = 1; d1 < 0; i++,d1++)//处理部门一人数超限
            {
                if(c1[i].nd.part == 1)//移入部门二
                {
                    c2[sc2+1].st = c1[i].st;
                    c2[sc2+1].nd = c1[i].nd;
                    c2[sc2+1].rd = c1[i].rd;
                    sc2++;sc1--;
                    sum -= c1[i].st.num;
                    sum += c1[i].nd.num;
                    c1[i].st.num = 0;c1[i].st.part = 0;
                    c1[i].nd.num = 0;c1[i].nd.part = 0;
                    c1[i].rd.num = 0;c1[i].rd.part = 0;
                }
                if(c1[i].nd.part == 2)//移入部门三
                {
                    c3[sc3+1].st = c1[i].st;
                    c3[sc3+1].nd = c1[i].nd;
                    c3[sc3+1].rd = c1[i].rd;
                    sum -= c1[i].st.num;
                    sum += c1[i].nd.num;
                    c1[i].st.num = 0;c1[i].st.part = 0;
                    c1[i].nd.num = 0;c1[i].nd.part = 0;
                    c1[i].rd.num = 0;c1[i].rd.part = 0;
                }
            }
        }

        if(d2<0)
        {
            sort(c2,c2+sc2,cmp_club);//按第二高降序排列
            for(int i = 1; d2 < 0; i++,d2++)//处理部门一人数超限
            {
                if(c2[i].nd.part == 1)//移入部门一
                {
                    c1[sc1+1].st = c2[i].st;
                    c1[sc1+1].nd = c2[i].nd;
                    c1[sc1+1].rd = c2[i].rd;
                    sc1++;sc2--;
                    sum -= c2[i].st.num;
                    sum += c2[i].nd.num;
                    c2[i].st.num = 0;c2[i].st.part = 0;
                    c2[i].nd.num = 0;c2[i].nd.part = 0;
                    c2[i].rd.num = 0;c2[i].rd.part = 0;
                }
                if(c2[i].nd.part == 3)//移入部门三
                {
                    c3[sc3+1].st = c2[i].st;
                    c3[sc3+1].nd = c2[i].nd;
                    c3[sc3+1].rd = c2[i].rd;
                    sc3++;sc2--;
                    sum -= c2[i].st.num;
                    sum += c2[i].nd.num;
                    c2[i].st.num = 0;c2[i].st.part = 0;
                    c2[i].nd.num = 0;c2[i].nd.part = 0;
                    c2[i].rd.num = 0;c2[i].rd.part = 0;
                }
            }
        }
        if(d3<0)
        {
            sort(c3,c3+sc3,cmp_club);//按第二高降序排列
            for(int i = 1; d3 < 0; i++,d3++)//处理部门三人数超限
            {
                if(c3[i].nd.part == 1)//移入部门一
                {
                    c1[sc1+1].st = c3[i].st;
                    c1[sc1+1].nd = c3[i].nd;
                    c1[sc1+1].rd = c3[i].rd;
                    sc1++;sc3--;
                    sum -= c3[i].st.num;
                    sum += c3[i].nd.num;
                    c3[i].st.num = 0;c3[i].st.part = 0;
                    c3[i].nd.num = 0;c3[i].nd.part = 0;
                    c3[i].rd.num = 0;c3[i].rd.part = 0;
                }
                if(c3[i].nd.part == 2)//移入部门二
                {
                    c2[sc2+1].st = c3[i].st;
                    c2[sc2+1].nd = c3[i].nd;
                    c2[sc2+1].rd = c3[i].rd;
                    sc2++;sc3--;
                    sum -= c3[i].st.num;
                    sum += c3[i].nd.num;
                    c3[i].st.num = 0;c3[i].st.part = 0;
                    c3[i].nd.num = 0;c3[i].nd.part = 0;
                    c3[i].rd.num = 0;c3[i].rd.part = 0;
                }
            }
        }
        cout << sum << endl;
        for(int i = 1; i <= n; i++)
        {
            c1[i].st.num = 0;c1[i].st.part = 0;
            c1[i].nd.num = 0;c1[i].nd.part = 0;
            c1[i].rd.num = 0;c1[i].rd.part = 0;
        }
        for(int i = 1; i <= n; i++)
        {
            c2[i].st.num = 0;c2[i].st.part = 0;
            c2[i].nd.num = 0;c2[i].nd.part = 0;
            c2[i].rd.num = 0;c2[i].rd.part = 0;
        }
        for(int i = 1; i <= n; i++)
        {
            c3[i].st.num = 0;c3[i].st.part = 0;
            c3[i].nd.num = 0;c3[i].nd.part = 0;
            c3[i].rd.num = 0;c3[i].rd.part = 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
