#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000000;
int ans[MAXN+5];
int ans_idx = 0;
bool cmp(int a , int b) // Unused.
{
    return a >= b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string num_string;
    cin >> num_string;
    for(int i = 0 ; i < num_string.length() ; i++)
    {
        if (isdigit(num_string[i]))
        {
            //printf("%d ",num_string[i] - '0');
            ans[ans_idx++] = num_string[i] - '0';
            //printf("Saved:%d\n",ans[ans_idx-1]);
        }

    }
    //printf("\n");
    sort(ans,ans+ans_idx);
    for(int i = ans_idx - 1; i >= 0 ; i--)
    {
        cout << ans[i];
    }
}
