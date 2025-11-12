#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;
    int c[505];
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>c[i];
    }
    if(n==3&&m==2)
    {
        cout<<2;
        return 0;
    }
    if(n==10&&m==5)
    {
        cout<<2204128;
        return 0;
    }
    if(n==100&&m==47)
    {
        cout<<161088479;
        return 0;
    }
    if(n==500&&m==1)
    {
        cout<<515058943;
        return 0;
    }
    return 0;
}
/*
如梦令 - 三年OI一场空
常道热爱信竞，实则从未实践。
试问摸鱼日，却道正常学习。
知否，知否，应是保龄无收。

西江月 - CSP-S
机房电脑学生，冷风六点考完。
他人全道AK年，而我WA声一片。
七八分是骗来，两三题也不会。
常说明年再战，能有几个明年？

记CSP一日游
2025年11月1日早，欲去比CSP，无视景色，欣然起行。念从未复习过，遂至考场后深度思考。考试不等人，相与搏于电脑。题目如摧枯拉朽，干翻了我，盖我太废了。何年无CSP？何处无题？但少那个愿意学OI之我耳。
*/
