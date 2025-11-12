#include <bits/stdc++.h>
// #include <dragonpro.h>
// #define ll long long
// #define pr pair<,>
using namespace std;
const int MAXN = 500010;
int n , k , a[MAXN]; // 2^20 = 1048579
string num_in_2[1048580];
void part_scores_1()
{
    int cnt = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(a[i] == 0) cnt ++;
        else if(a[i] == 1 && a[i + 1] == 1)
            cnt ++ , i ++;
    }
    cout << cnt << endl;
    exit(0);
}
void part_scores_2()
{
    int cnt = 0;
    for(int i = 1 ; i <= n ; i ++)
        if(a[i] == 1) cnt ++;
    cout << cnt << endl;
    exit(0);
}
// void prev()
// {
//     for(int i = 1 ; i <= 1048579 ; i ++)
//     {

//     }
// }
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin >> n >> k;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    if(k == 0) part_scores_1();
    if(k == 1) part_scores_2();

	return 0;
}
// dragonpro-presents