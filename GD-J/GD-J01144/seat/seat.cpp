#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int mapp[15][15];
int main()
{
    ifstream inn;
    ofstream outt;
    inn.open("seat.in");
    outt.open("seat.out");

    vector<int> score;
    int n,m;
    inn>>n>>m;
    int num,rzscore;//R's score
    num=n*m;
    for(int i=0;i<num;i++)
    {
        int temp; 
        inn>>temp;
        score.push_back(temp);
    }
    rzscore = score[0];
    sort(score.begin(),score.end(),cmp);
    int pos,cnt=0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cnt++;
            int realm;
            if(i%2==0)//dang qian wei ji shu lie
            {
                realm= m-j+1;
            }
            else
            {
                realm = j;
            }
            mapp[i][realm]= score[cnt-1];
            //outt<<i<<' '<<realm<<' '<<score[cnt-1]<<"<-debug1    ";
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            //outt<<mapp[i][j]<<"<-debug    "<<i<<' '<<j<<"<-debug   ";
            if(mapp[i][j]== rzscore)
            {
                outt<<i<<' '<<j;
                inn.close();
                outt.close();
                return 0;
            }
        }
    }
    /*for(int i=0;i<score.size();i++)
    {
        if(score[i]==rzscore){
            pos =i;
            break;
        }
    }
    int ansn,ansm;
    ansn= pos/m;
    if(ansn%2==0)
    {
        ansm=m-(pos - (m*(ansn-1)));

    }
    else if(ansn %2==1)
    {
        ansm = pos -(m*(ansn-1));
    }
    outt<<ansn<<' '<<ansm;

    inn.close();
    outt.close();
    return 0;*/
}