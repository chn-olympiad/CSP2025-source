#include <bits/stdc++.h>
using namespace std;
int n,m,x[109],y[109];
struct lblsl{
    int z=0;
    bool br=0;
};
lblsl a[109];
bool cmd(lblsl q,lblsl p){
    return q.z>p.z;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    int hang=1,lie=1;
    a[0].br=1;
    bool b=0;
    for(int i=0;i<n*m;i++)
    {
        if(hang>n)
        {
            hang=n;
            lie++;
            b=1;
        }
        if(hang<1)
        {
			hang=1;
			lie++;
			b=0;
		}
        cin>>a[i].z;
		x[i]=hang;
        y[i]=lie;
        if(b==0) hang++;
        if(b==1) hang--;
    }
    sort(a,a+n*m,cmd);
    for(int i=0;i<n*m;i++)
    {
        if(a[i].br==1)
        {
            cout<<y[i];
            cout<<' ';
            cout<<x[i];
            return 0;
        }
    }
    return 0;
}
