#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e5 +  7 ;
int T ;
int n ;
long long ans = 0 ;
struct stu
{
    int id , a , b , c , cha ;
    int maxn ,minn ;
}a[N];

bool checka()
{
    for(int i = 1 ; i <= n ; i++ )
    {
        if( a[i].b != 0 ||a[i].c != 0 )return false;
    }
    return true;
}

bool checkb()
{
    for(int i = 1 ; i <= n ; i++ )
    {
        if( a[i].c != 0 )return false;
    }
    return true;
}
bool cmpa(stu x , stu y)
{
    return x.a >y.a ;
}
bool cmpb( stu x , stu y )
{
    return x.cha > y.cha ;
}

int cnt[5];
int q[N];

void dfs(int x , long long sum )
{
    if( x > n )
    {

        ans = max(ans , sum );
        return ;
    }
    if( (cnt[1] +1) <= n / 2 )
    {
        cnt[1]+=1;
        q[x ] = 1 ;
        dfs(x+1,sum+a[x].a );
        cnt[1]-=1;
    }
    if( (cnt[2] +1 ) <= n / 2 )
    {
        cnt[2]+=1;
        q[x] = 2 ;
        dfs(x+1,sum + a[x].b);
        cnt[2]-=1;
    }
    if( (cnt[3] +1 )<= n / 2 )
    {
        cnt[3]+=1;
        q[x] = 3 ;
        dfs(x+1 , sum + a[x].c );
        cnt[3]-=1;
    }
}


int main()
{
    freopen("club.in","r" , stdin );
    freopen( "club.out" , "w" , stdout );
    cin >> T;
    while(T--)
    {
        ans = 0 ;
        memset(a , 0 , sizeof a );
        cin >> n ;
        for(int i = 1 ; i <= n ; i++ )
        {
            a[i].id = i ;
            cin >> a[i].a >> a[i].b >> a[i].c ;
            a[i].cha = a[i].a - a[i].b ;
        }
        if(checka())
        {
            sort(a +1 , a + n + 1 , cmpa );

            for( int i = 1 ; i <= n / 2 ; i++ )
            {
                ans += a[i].a;
            }
            cout << ans ;
        }
        else if(checkb() )
        {

            sort( a +1 , a +n + 1  ,cmpb );
            for( int i = 1 ; i <= n / 2 ; i++ )
            {

                ans += a[i].a ;

            }
            for( int i = n / 2 +1 ; i <= n ; i++ )
            {
                ans += a[i].b ;
            }

            cout <<ans << "\n";
        }
        else
        {
            memset( cnt , 0 , sizeof cnt );
            dfs(1,0);
            //cout << n << " ";
            cout <<ans <<"\n";
        }
    }


    return 0 ;
}
