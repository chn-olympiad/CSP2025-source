#include<bits/stdc++.h>
using namespace std;
struct node
{
    int score;
    bool xiaoming;
}data[502];
int n,m,cnt,rnk;
bool cmp(node a,node b)
{
    return a.score>b.score;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cnt++;
            cin>>data[cnt].score;
        }
    }
    data[1].xiaoming=true;
    sort(data+1,data+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
        if(data[i].xiaoming)
            rnk=i;
    }
    //cout<<rnk<<'\n';
    int col=(rnk-1)/n+1;
    int rw=rnk-(col-1)*n;
    if(col%2==1)
        cout<<col<<' '<<rw;
    else
        cout<<col<<' '<<n-rw+1;
    return 0;
}
//freopen("seats.in","r",stdin);
//freopen("seats.out","w",stdout);
//haha.
//plural.
//someone must have done this:)

//100+100+100+100=400
//AK?
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
