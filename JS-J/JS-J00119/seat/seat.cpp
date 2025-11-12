#include <bits/stdc++.h>
using namespace std;

int n,m;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","a",stdout);
    cin >> n >> m;
    int len = n*m+1;
    int arr[len];
    int seat[n+1][m+1];
    for(int i = 1; i <= len-1; i++)
    {
        cin >> arr[i];
    }
    int ans = arr[1];
    for(int i = 1; i <= len-2; i++)
    {
        int max = arr[i];
        for(int j = i+1; j <= len-1; j++)
        {
            if(arr[j] > arr[i])
            {
                swap(arr[i],arr[j]);
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        int tmp[n];
        int z = 1;
        if(i%2 == 1)
        {
            for(int k = (i-1)*n+1; k <=(i-1)*n+n; k++)
            {
                tmp[z] = arr[k];
                z++;
            }
        }
        else
        {
            for(int k =(i-1)*n+n; k >=(i-1)*n+1; k--)
            {
                tmp[z] = arr[k];
                z++;
            }
        }
        for(int j = 1; j <= n; j++)
        {
            seat[j][i] = tmp[j];
            if(seat[j][i] == ans)
            {
                cout << i << " " << j;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
