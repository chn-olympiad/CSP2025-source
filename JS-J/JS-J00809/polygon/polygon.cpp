#include<bits/stdc++.h>

using namespace std;

// I wonder sometimes when you are asleep
// have you ever dreamt of me



long long stat;
long long ans;
long long arr[25];
vector<int> selected;
// int st[505][10];
// int Log[505];

// void init()
// {
//     Log[0] = 0;
//     Log[1] = 0;
//     for(int i = 2 ; i <= 3 ; i++)
//     {
//         Log[i] = 1;
//     }
//     for(int i = 3 ; i <= 7 ; i++)
//     {
//         Log[i] = 2;
//     }
//     for(int i = 8 ; i <= 15 ; i++)
//     {
//         Log[i] = 3;
//     }
//     for(int i = 16 ; i <= 31 ; i++)
//     {
//         Log[i] = 4;
//     }
//     for(int i = 32 ; i <= 63 ; i++)
//     {
//         Log[i] = 5;
//     }
//     for(int i = 64 ; i <= 127 ; i++)
//     {
//         Log[i] = 6;
//     }
//     for(int i = 128 ; i <= 255 ; i++)
//     {
//         Log[i] = 7;
//     }
//     for(int i = 256 ; i <= 511 ; i++)
//     {
//         Log[i] = 8;
//     }
//     Log[512] = 9;
// }

long long quick_pow(long long a , long long b)
{
    if(b == 1)
    {
        return a;
    }
    else if(b == 0)
    {
        return 1;
    }
    else
    {
        if(b & 1)
        {
            long long ans = quick_pow(a , b / 2);
            return ans * ans * a;
        }
        else
        {
            long long ans = quick_pow(a , b / 2);
            return ans * ans;
        }
    }
}

int Pow[25] = {1 , 2 , 4 , 8 , 16 , 32 , 64 , 128 , 256 , 512 , 1024, 2048 , 4096 , 8192 , 16384 , 32768 , 65536 , 131072 , 262144 , 524288 , 1048576 , 2097152 , 4194304};

int main()
{
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }

    // for(int i = 1 ; i <= n ; i++)
    // {
    //     st[i][0] = arr[i];
    // }
    // for(int j = 1 ; j <= 9 ; j++)
    // {
    //     for(int i = 1 ; i <= n ; i++)
    //     {
    //         st[i][j] = max(st[i][j - 1] , st[i + (1 << (j - 1))][j - 1]); 
    //     }
    // }
    //cerr<<Pow[n];
    //cerr<<n;
    for(stat = 0 ; stat < Pow[n] ; stat++)
    {
        selected.clear();
        for(int i = 0 ; i <= n ; i++)
        {
            if((stat >> i) & 1)
            {
                selected.push_back(arr[i]);
                //cerr<<"pushed";
            }
        }
        long long sum = 0;
        int maxn = INT_MIN;
        for(int i = 0 ; i < selected.size() ; i++)
        {
            sum += selected[i];
            if(selected[i] >= maxn)
            {
                maxn = selected[i];
            }
        }
        if(sum > maxn * 2)
        {
            ans = (ans + 1) % 998244353;
        }
        // for(int i = 0 ; i < selected.size() ; i++)
        // {
        //     cerr<<" "<<selected[i];
        // }
        // cerr<<"\n";
        
    }

    cout<<ans;

	return 0;
} 