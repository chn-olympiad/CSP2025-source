#include<bits/stdc++.h>
int n,m;
int studentnumber;
int a[110];
int Rx,Ry;
using namespace std;
void where(int x,int y,int i)
{
//    std::cout << "x" << x << " y" << y << " i" << i << std::endl;
    if(a[i]==a[0])
    {
        Rx=x;
        Ry=y;
        return;
    }
    if(x%2==1)
    {
        if(y==m) where(x+1,y,i-1);
        else where(x,y+1,i-1);
    }
    else
    {
        if(y==1) where(x+1,y,i-1);
        else where(x,y-1,i-1);
    }
    return;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	studentnumber=n*m;
	for(int i=0;i<studentnumber;i++)
    {
        cin >> a[i];
    }
    a[studentnumber]=a[0];
    sort(a+1,a+studentnumber+1);
    where(1,1,studentnumber);
    cout << Rx << " " << Ry << endl;
	return 0;
}
