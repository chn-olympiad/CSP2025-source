#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int wz=1,n,m,num;
	cin>>n>>m>>num;
	for(int i=1;i<(n*m);i++)
    {
        int temp;
        cin>>temp;
        if(temp>num)
        {
            wz++;
        }
    }

    int h=(wz%(n*2));
    int l=(wz/n)+1;

    if(h>n)
    {
        h=2*n-h+1;
    }
    else if(h==n)
    {
        l--;
    }
    else if(h==0)
    {
        h=1;
        l--;
    }
    cout<<l<<" "<<h;

    fclose(stdin);
	fclose(stdout);

	return 0;
}
