#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,mx,data[5002],dp[5002],ans;
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>data[i];
        mx=max(mx,data[i]);
    }
    sort(data+1,data+n+1);
    for(int i=0;i<=data[1];i++)
    {
        dp[i]=1;
        //dp[1][i][0]=1;
    }
    dp[0]=2;
    //dp[1][0][0]=2;
    for(int i=2;i<=n;i++)
    {
        ans+=dp[data[i]+1];
        ans%=998244353;
        //cout<<dp[data[i]+1]<<'\n';
        for(int j=mx*2;j>=0;j--)
        {
            if(j>=data[i])
                dp[j]=dp[j]+dp[j-data[i]];
            else
                dp[j]=dp[j]+dp[0];
            dp[j]%=998244353;
        }
    }
    cout<<ans;
    return 0;
}
//polygen
//poligon
//poligen
//typos so fun!
//∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑
//;)
//sigma!
//ACed
//100+100+100+100=400
//wish for AK
//luogu uid 772817 mfh123
/*
I'm gotta write an essay here.
Okay.
I wanted to write this in Chinese,but I can't find the input :(
Whatever. My English is good enough.

This is my third year at CSP-J.
Last year, I attended -S too.
But...well, to put it straight ,I //freopen ed.
If I had not //freopen ed, I would have a chance at NOIP.
But I did.
Today is my second chance.
I WILL GO TO NOIP THIS YEAR!
And that's it.

But even though I'm only at seven grade, I might AK CSP-J.
Look,you might think that I'm bluffing. But I'm not.
I finished the first and second problem with half an hour.
I'm sure that I can get at least 200 pts.
The third problem needs only map and greedy.
This problem, as you can see, is a DP.
(Whoa, that rhymes!)
I'm pretty sure I got those right.
My programs passed all of the large samples.
Except for problem A,#4. That's too large a sample.
Last year, I got 300 pts on CSP-J.
This year, I wanna get AK!

For OIers like me, don't get disappointed if you //freopen ed on a large event.
There's more to do, more to learn!
Never underestimate yourself.
Next year would be better!
You'll improve on this year too, don't AFO just yet!
Become the best for yourself.
If you really want to, you can AFO.
Just don't give up too early!
+-0 is safe, but neither is it good.

Whoa, I have written so much!
Wish you all good luck at CSP/NOIP/NOI.
And if you are a super good OIer, wish you good luck at IOI.
Goodbye.
For ever.

--mfh123
Written on November first, 2025.

P.S. Learning English is important. You can write essays when you are bored. :)
P.P.S. Maybe not goodbye forever. just use luogu to send stuff to me.
*/
