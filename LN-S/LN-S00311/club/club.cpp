#include<bits/stdc++.h>//Ren5Jie4Di4Ling5%
using namespace std;
int z[6];
int a[1000000];
int b[1000000];
int c[1000000];
void linshi()
{
    int w[10];
    w[1]=a[1]+a[2];
    w[2]=a[1]+b[2];
    w[3]=a[1]+c[2];
    w[4]=b[1]+a[2];
    w[5]=b[1]+b[2];
    w[6]=b[1]+c[2];
    w[7]=c[1]+a[2];
    w[8]=c[1]+b[2];
    w[9]=c[1]+c[2];
    sort(w+1,w+10);
    printf("%d",w[9]);
}
void comparing(int n)
{
    int score=0;
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        sort(c+1,c+n+1);
    int middlen=n/2;
    for(int i=n;i>middlen;i--)
    {
        score+=a[i];
    }
    for(int i=n;i>middlen;i--)
    {
        score+=b[i];
    }
        int linshi1=middlen+1;
        int linshi2=middlen+1;
    for(int i=n;i>=middlen;i--)
    {
        if(((score-a[linshi1]+c[i])>score)&&((score-b[linshi2]+c[i])<(score-a[linshi1]+c[i])))
        {
            score=score-a[linshi1]+c[i];
            linshi1++;
        }
        if((score-b[linshi2]+c[i]>score)&&(score-a[linshi1]+c[i]<score-b[linshi2]+c[i]))
        {
            score=score-b[linshi2]+c[i];
            linshi2++;
        }
    }
    printf("%d\n",score);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&z[i]);
        n=z[i];
        for(int j=1;j<=n;j++)
        {scanf("%d%d%d",&a[j],&b[j],&c[j]);
        if(n==2)
        {
            linshi;
        }
       }comparing(n);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


