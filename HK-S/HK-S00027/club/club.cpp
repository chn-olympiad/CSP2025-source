#include <bits/stdc++.h>
using namespace std;

int T=0;
int N=0;
int counter=0;
long long sumi=0;
long long lovenum[5]={};
multiset <long long> temper;
struct membership{
    long long lover1=0,lover2=0,lover3=0;
    long long changedecrease=0;
    int prefered;

};
membership cluber[200005];
//g++ -O2 -std=c++14 -static club.cpp -o club

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin >> T;
    for(int ii=1;ii<=T;ii++)
    {
        cin >> N;
        lovenum[1]=0;
        lovenum[2]=0;
        lovenum[3]=0;
        sumi=0;
        for(int i=1;i<=N;i++)
        {
            cin >> cluber[i].lover1 >> cluber[i].lover2 >> cluber[i].lover3;
            if(cluber[i].lover1>=cluber[i].lover2&&cluber[i].lover1>=cluber[i].lover3)
            {
                cluber[i].prefered=1;
                lovenum[1]++;
                cluber[i].changedecrease=min(cluber[i].lover1-cluber[i].lover2,cluber[i].lover1-cluber[i].lover3);
                sumi+=cluber[i].lover1;
                continue;
            }
            else
            {
                if(cluber[i].lover2>=cluber[i].lover3)
                {
                    cluber[i].prefered=2;
                    lovenum[2]++;
                    cluber[i].changedecrease=min(cluber[i].lover2-cluber[i].lover1,cluber[i].lover2-cluber[i].lover3);
                    sumi+=cluber[i].lover2;
                    continue;

                }
                else
                {
                    cluber[i].prefered=3;
                    lovenum[3]++;
                    cluber[i].changedecrease=min(cluber[i].lover3-cluber[i].lover2,cluber[i].lover3-cluber[i].lover1);
                    sumi+=cluber[i].lover3;
                    continue;

                }
            }
        }
        if(lovenum[1]<=N/2&&lovenum[2]<=N/2&&lovenum[3]<=N/2)
        {
            cout << sumi << endl;
            continue;
        }
        temper.clear();
        for(int j=1;j<=3;j++)
        {
            if(lovenum[j]>N/2)
            {
                for(int i=1;i<=N;i++)
                {
                    if(cluber[i].prefered==j)
                    {
                        temper.insert(cluber[i].changedecrease);
                    }
                }
                for(auto it=temper.begin();it!=temper.end();it++)
                {
                    sumi-=*it;
                    lovenum[j]--;
                    if(lovenum[j]<=N/2){break;}
                }

                cout << sumi << endl;
                break;
            }
        }

    }
    return 0;
}