#include<bits/stdc++.h>
using namespace std;
int n ,m ,pw;
int tmpm=0,tmpn=0;
int rscore =0;
int score[1000];


int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    
    cin >>n >>m;
    
    for(int i =1;i <=n*m;i++)
    {
        cin >>score[i];
        if(i ==1) rscore =score[i];
        
    }
    sort(score +1,score +1 +(n *m));
    
    for(int i =n*m;i >=1;i--)
    {
        if(score[i] ==rscore)
        {
	
            pw =(n *m) -i +1;
        }
    }
    
    if(pw %n ==0)
    {
        tmpm =pw /n;
    }
    else
    {
        tmpm =(pw /n) +1;
    }
    if(tmpm %2 ==0)
    {
        if(pw %n ==0)
        {
            tmpn =1;
        }
        else
        {
            tmpn =(n+1) -(pw %n);
        }
    }
    else
    {
        if(pw %n ==0)
        {
            tmpn =n;
        }
        else
        {
            tmpn =(pw %n);
        }
    }
    cout <<tmpm <<' '<<tmpn;
    return 0;
}
