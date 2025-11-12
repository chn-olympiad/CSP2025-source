#include<bits/stdc++.h>
using namespace std;
int b[105],p,m,a,num;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> p >> m;
    for(int i = 1;i <= p * m;i++)
    {
        cin >> b[i];
    }
    a = b[1];
    sort(b + 1, b + p * m + 1);
    for(int i = 1;i <= p * m;i++)
    {
        if(a == b[i])
        {
            num = i;
            break;
        }
    }
    num = p * m - num + 1;
    cout << num << endl;
    cout << (num - 1) / p + 1 << " ";
    if((((num - 1) / p) + 1) % 2 == 0) cout << (m - ((num - 1) % p));
    else cout << (num - 1) % p + 1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
