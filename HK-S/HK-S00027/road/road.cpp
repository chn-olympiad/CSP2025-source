#include <bits/stdc++.h>
using namespace std;

bool flag=false;
int N=0;
int K=0;
int M=0;
int Knum[50]={};
long long Kcost[50]={};
long long ptsave=0;
long long temper=0;
long long currentK[20005];
//g++ -O2 -std=c++14 -static road.cpp -o road
struct roader
{
    int starter=0;
    int ender=0;
    long long coster=0;
    int Ker=0;
    bool activer=false;
    bool operator < (const roader& other) const
    {
        if(coster!=other.coster){return coster<other.coster;}
        if(starter!=other.starter){return starter<other.starter;}
        return ender<other.ender;
    }
};

set <roader> roads;
set <roader> waitingroads;
set <roader> usefulroads;
roader temproad,temproad2;
set <int> citys;
set <int> tempcitys;
long long totalcost=0;

void moveroads(int KK)
{
    for(auto it=roads.begin();it!=roads.end();it++)
    {
        temproad2=*it;
        if(temproad2.starter==KK||temproad2.ender==KK)
        {
            waitingroads.insert(*it);
            

        }
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> N >> M >> K;
    if(N==1)
    {
        cout << "0" << endl;
        return 0;
    }
    for(int i=1;i<=M;i++)
    {
        cin >> temproad.starter >> temproad.ender >> temproad.coster;
        roads.insert(temproad);
    }
    temproad=*roads.begin();
    citys.insert(temproad.starter);
    citys.insert(temproad.ender);
    tempcitys=citys;
    totalcost+=temproad.coster;
    usefulroads.insert(*roads.begin());
    moveroads(temproad.starter);
    moveroads(temproad.ender);

    while(citys.size()<N)
    {
        if(waitingroads.empty()){cout << "0" << endl;return 0;}
        temproad=*waitingroads.begin();
        if(citys.find(temproad.starter)!=citys.end()&&citys.find(temproad.ender)!=citys.end())
        {
            waitingroads.erase(waitingroads.begin());
            continue;
        }


        citys.insert(temproad.starter);
        if(tempcitys.size()+1==citys.size()){tempcitys=citys;moveroads(temproad.starter);}
        citys.insert(temproad.ender);
        if(tempcitys.size()+1==citys.size()){tempcitys=citys;moveroads(temproad.ender);}
        totalcost+=temproad.coster;

        usefulroads.insert(*waitingroads.begin());
        waitingroads.erase(waitingroads.begin());
    }

    roads.clear();
    waitingroads.clear();

    for(int i=1;i<=K;i++)
    {
        cin >> Kcost[i];
        for(int j=1;j<=N;j++)
        {
            cin >> currentK[j];
        }
        ptsave=0;
        flag=false;
        for(auto it=usefulroads.begin();it!=usefulroads.end();it++)
        {
            temproad=*it;
            if(currentK[temproad.starter]+currentK[temproad.ender]<temproad.coster)
            {
                ptsave+=(temproad.coster-currentK[temproad.starter]-currentK[temproad.ender]);
                if(ptsave>Kcost[i]){flag=true;break;}
            }
        }
        if(!flag){continue;}
        ptsave=-Kcost[i];
        roads.clear();
        for(auto it=usefulroads.begin();it!=usefulroads.end();it++)
        {
            temproad=*it;
            if(currentK[temproad.starter]+currentK[temproad.ender]<temproad.coster)
            {
                ptsave+=(temproad.coster-currentK[temproad.starter]-currentK[temproad.ender]);
                temproad.coster=currentK[temproad.starter]+currentK[temproad.ender];
                
                if(temproad.Ker!=0){Knum[temproad.Ker]--;if(Knum[temproad.Ker]==0){totalcost-=Kcost[i];}}
                

                temproad.Ker=i;
                Knum[i]++;
            }
            roads.insert(temproad);
        }
        usefulroads=roads;
        totalcost-=ptsave;


        

    }
    cout << endl << totalcost << endl;
    








    return 0;
}