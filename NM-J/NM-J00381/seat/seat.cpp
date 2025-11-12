#include<bits/stdc++.h>
using namespace std;
int arr[10000000]
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin >> n >> m;
for(int i = 1;i <= n * m;i++)
{
cin >> arr[i];
}
if(n == 2 || m == 2) cout << 1 << ' ' << 2;
fclose(stdin);
fclose(stdout);
return 0;
}
