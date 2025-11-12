#include<bits/stdc++.h>
using namespace std;

int a[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            a[(int)(s[i]-'0')]++;
        }
    }
    for(int i = 9;i >= 0;i--)
    {
        for(int j = 1;j <= a[i];j++)
        {
            cout << i;
        }
    }
    return 0;
}
/*
Look one by one
The pages remind you'll always be a villian
For you,angels have fallen
Now they are gone
See? Now they are gone
Forever gone
From the hell served as my one and only home
It may hurt today
Tomorrow I'll be heading my way
I tried,I tried
How do I expect
My dearest friend
Tell me when,when shall we make it end
So let me take your hand
Like one of those madman
Titipity tapatipa
Dance our last dance
For lsy.
*/
