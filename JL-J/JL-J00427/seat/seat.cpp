#include<bits/stdc++.h>
using namespace std;
int n , m , a[110];
bool cmp(int x , int y) {return x > y;}
int main()
{
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    scanf("%d%d" , &n , &m);
    for(int i = 1 ; i <= n * m ; i ++) scanf("%d" , &a[i]);
    int qwq = a[1];
    sort(a + 1 , a + n * m + 1 , cmp);
    int x = 1 , y = 0; // lie , hang
    // if(qwq == a[1]) printf("1 1\n") , exit(0);
    for(int i = 1 ; i <= n * m ; i ++)
    {
        if((y == n && (x % 2 == 1)) || (y == 1 && (x % 2 == 0))) x ++;
        else
        {
            if(x % 2 == 1) y ++;
            else y --;
        }
        // if(qwq == a[i])
        // {
            // if(qwq == a[i]) printf("*****\n");
            // printf("%d %d %d\n" , a[i] , x , y);
        if(qwq == a[i]) printf("%d %d\n" , x , y);
        // }
        // if((y == n && (x % 2 == 1)) || (y == 1 && (x % 2 == 0))) x ++;
        // else
        // {
        //     if(x % 2 == 1) y ++;
        //     else y --;
        // }
        // printf("***%d %d" , x , y);
    }
    return 0;
}

// #Shang4Shan3Ruo6Shui4