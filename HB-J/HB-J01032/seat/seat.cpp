#include<iostream>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int lines,cols;
    cin>>lines>>cols;
    int l[lines*cols];
    for(int i=0;i<lines*cols;i++)
        cin>>l[i];
    int score=l[0];
    for(int i=0;i<lines*cols;i++)
        for(int j=i;j<lines*cols-1;j++)
            if(l[i]<l[i+1])
            {
                int tmp=l[i+1];
                l[i+1]=l[i];
                l[i]=tmp;
            }
    int line=1,col=1;
    if(l[0]==score)
    {
        cout<<"1 1";
        return 0;
    }
    for(int i=0;l[i]!=score&&i<lines*cols;i++)
    {
        if(line>=lines&&(col%2))
        {
            col++;
            continue;
        }
        if(line<=1&&(!(col%2)))
        {
            col++;
            continue;
        }
        if(col%2)
            line++;
        else
            line--;

    }
    cout<<col<<" "<<line;
    return 0;
}
