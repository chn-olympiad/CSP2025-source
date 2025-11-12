#include<bits/stdc++.h>
using namespace std;
int hang=3,lie=1;
int mark[91];
int mymark;
int jhang=1,jlie=1;//find's out
int find(int marki)
{
    if(mark[marki-1]==mymark)return 0;
    if(jlie%2==1)
    {
        if(jhang==hang)
        {
            jlie++;
        }
        else
        {
            jhang++;
        }
        return find(marki-1);
    }
    else if(jlie%2==0)
    {
        if(jhang==1)
        {
            jlie++;
        }
        else
        {
            jhang--;
        }
        return find(marki-1);
    }
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>hang>>lie;
    cin>>mymark;
    mark[0]=mymark;
    for(int i=1;i<hang*lie;i++)
    {
        cin>>mark[i];
    }
    sort(mark,mark+hang*lie);
    find(hang*lie);
    cout<<jlie<<' '<<jhang;
    //for(int i=hang*lie-1;i>=0;i--)
    //{
        //cout<<mark[i]<<endl;
    //}
	return 0;
}
