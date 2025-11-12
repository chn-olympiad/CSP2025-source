#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,group1,group2,group3;
int n,limit,ans,jsq = 1;
int student[100000][3];
bool studentif[100000][3];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for(int ti=1;ti<=t;ti++)
    {
        ans = 0;
        group1 = 0;
        group2 = 0;
        group3 = 0;
        cin >> n;
        limit = n/2;
        for(int i=1;i<=n;i++)
        {
            studentif[i][1] = false;
            studentif[i][2] = false;
            studentif[i][3] = false;
            cin >> student[i][1] >> student[i][2] >> student[i][3];
            if(student[i][1] >= student[i][2] && student[i][1]>=student[i][3])
            {
                group1++;
                ans+=student[i][1];
                studentif[i][1] = true;
            }
            else if(student[i][2] >= student[i][1] && student[i][2]>=student[i][3])
            {
                group2++;
                ans+=student[i][2];
                studentif[i][2] = true;
            }
            else if(student[i][3] >= student[i][1] && student[i][3]>=student[i][2])
            {
                group3++;
                ans+=student[i][3];
                studentif[i][3] = true;
            }
        }
        bool flag = false;
        jsq = 1;
        while(group1 > limit)
        {
            for(int i=1;i<=n;i++)
            {
                if(studentif[i][1] == true && student[i][2] == student[i][1]-jsq && group2<limit)
                {
                    group1--;
                    group2++;
                    ans-=jsq;
                    studentif[i][2] == true;

                }
                else if(studentif[i][1] == true && student[i][3] == student[i][1]-jsq && group3<limit)
                {
                    group1--;
                    group3++;
                    ans-=jsq;
                    studentif[i][3] == true;

                }
            }
            jsq++;
        }
        jsq = 1;
        while(group2 > limit)
        {
            for(int i=1;i<=n;i++)
            {
                if(studentif[i][2] == true && student[i][1] == student[i][2]-jsq && group1<limit)
                {

                    group2--;
                    group1++;
                    ans-=jsq;
                    studentif[i][1] == true;
                }
                else if(studentif[i][2] == true && student[i][3] == student[i][2]-jsq && group3<limit)
                {

                    group2--;
                    group3++;
                    ans-=jsq;
                    studentif[i][3] == true;
                }
            }
            jsq++;
        }
        jsq = 1;
        while(group3 > limit)
        {
            for(int i=1;i<=n;i++)
            {
                if(studentif[i][3] == true && student[i][1] == student[i][3]-jsq && group1<limit)
                {
                    group3--;
                    group1++;
                    ans-=jsq;
                    studentif[i][1] == true;

                }
                else if(studentif[i][3] == true && student[i][2] == student[i][3]-jsq && group2<limit)
                {
                    group3--;
                    group2++;
                    ans-=jsq;
                    studentif[i][2] == true;

                }
            }
            jsq++;
        }
        cout << ans << endl;
    }
    return 0;
}
