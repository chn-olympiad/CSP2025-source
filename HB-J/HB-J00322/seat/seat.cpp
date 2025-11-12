#include <bits/stdc++.h>
using namespace std;
int n, m;
int s1;
int arr[1005];
int pos;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m >> s1;
    arr[0] = s1;
    int hei = n * m;
    for (int i = 1; i < hei; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + hei, cmp);
    for (int i = 0; i < hei; i++)
    {
        if (arr[i] == s1)
        {
            pos = i;
        }
    }
    pos += 1;
    int temp = pos / n;
    // for(int i=0;i<hei;i++){
    //     cerr<<arr[i]<<" ";
    // }
    // cerr<<s1<<endl;
    // cerr<<pos<<endl;
    temp += 1;
    if (temp % 2 == 0)
    {
        // if(pos%n==1){
        //     cout<<temp+1<<" "<<;
        // }
        if (pos % n == 0)
        {
            cout << temp - 1 << " " << n;
        }
        else
        {
            cout << temp << " " << (n - pos % n + 1);
        }
    }
    else
    {
        if (pos % n == 0)
        {
            cout << temp - 1 << " " << 1;
        }
        else
        {
            cout << temp << " " << (pos % n);
        }
    }
    return 0;
}
/*
4 5
8 1 2 3 4 5 6 7 10 11 12 13 14 15 16 17 18 19 20 9
*/
/*
3 3
94 95 96 97 98 99 100 93 92
*/