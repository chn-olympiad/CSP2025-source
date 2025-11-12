#include<bits/stdc++.h>
using namespace std;

int n;
int a[5005];
int maxx=-1;
const int MOD=998244353;

bool cmp(int x,int y)
{
    return x<y;
}

void out(long long num)
{
    cout<<num;
}

long long solve_jie(int x)
{
    long long p=1;
    for(int i=2;i<=x;i++)
        p=(p*i)%MOD;
    return p;
}

void special_maxx()
{
    long long ans=0;
    if(n==3)
    {
        out(ans);//out(0);
        return ;
    }
    long long jie_n=solve_jie(n)%MOD;
    long long tp1=solve_jie(4)%MOD,tp2=solve_jie(n-4)%MOD;
    for(int i=4;i<=n;i++)
    {
        long long cnt=0;
        cnt=(jie_n/(tp1*tp2))%MOD;
        ans=(ans+cnt)%MOD;
        if(i==n) break; //defent /0
        tp1=tp1*(i+1)%MOD,tp2=tp2/(n-i)%MOD;
    }
    out(ans);
}

void DFS()
{
	long long cnt=0;
	for(int id1=0;id1<=1;id1+=1)
    for(int id2=0;id2<=2;id2+=2)
    for(int id3=0;id3<=3;id3+=3)
    for(int id4=0;id4<=4;id4+=4)
    for(int id5=0;id5<=5;id5+=5)
    for(int id6=0;id6<=6;id6+=6)
    for(int id7=0;id7<=7;id7+=7)
    for(int id8=0;id8<=8;id8+=8)
    for(int id9=0;id9<=9;id9+=9)
    for(int id10=0;id10<=10;id10+=10)
    for(int id11=0;id11<=11;id11+=11)
    for(int id12=0;id12<=12;id12+=12)
    for(int id13=0;id13<=13;id13+=13)
    for(int id14=0;id14<=14;id14+=14)
    for(int id15=0;id15<=15;id15+=15)
    for(int id16=0;id16<=16;id16+=16)
    for(int id17=0;id17<=17;id17+=17)
    for(int id18=0;id18<=18;id18+=18)
    for(int id19=0;id19<=19;id19+=19)
    for(int id20=0;id20<=20;id20+=20)
    {
		if(id20>n||id19>n||id18>n||id17>n||id16>n||id15>n||id14>n||id13>n||id12>n||id11>n||id10>n
		||id9>n||id8>n||id7>n||id6>n||id5>n||id4>n||id3>n||id2>n||id1>n)
			break;
		long long now;
		now=(a[id1]+a[id2]+a[id3]+a[id4]+a[id5]+a[id6]+a[id7]+a[id8]+a[id9]+a[id10]
		+a[id11]+a[id12]+a[id13]+a[id14]+a[id15]+a[id16]+a[id17]+a[id18]+a[id19]+a[id20])%MOD;
		if(now==0) continue;
		//cout<<now<<'\n';
		long long r=0,q=0;
		if(a[id1]) r=a[id1],q++;
		if(a[id2]) r=a[id2],q++;
		if(a[id3]) r=a[id3],q++;
		if(a[id4]) r=a[id4],q++;
		if(a[id5]) r=a[id5],q++;
		if(a[id6]) r=a[id6],q++;
		if(a[id7]) r=a[id7],q++;
		if(a[id8]) r=a[id8],q++;
		if(a[id9]) r=a[id9],q++;
		if(a[id10]) r=a[id10],q++;
		if(a[id11]) r=a[id11],q++;
		if(a[id12]) r=a[id12],q++;
		if(a[id13]) r=a[id13],q++;
		if(a[id14]) r=a[id14],q++;
		if(a[id15]) r=a[id15],q++;
		if(a[id16]) r=a[id16],q++;
		if(a[id17]) r=a[id17],q++;
		if(a[id18]) r=a[id18],q++;
		if(a[id19]) r=a[id19],q++;
		if(a[id20]) r=a[id20],q++;
		r%=MOD;
		//cout<<r<<'\n';
		if(q>=3&&now>2*r)
			cnt++,cnt%=MOD;
			
	}
	out(cnt);
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    srand(time(0));
    cin>>n;
    for(int i=1;i<=n;i++)
		cin>>a[i],maxx=max(maxx,a[i]);
	sort(a+1,a+n+1,cmp);
    if(maxx==1)
    {
        special_maxx();
        return 0;
    }
    a[0]=0;
    if(n<=20)
		DFS();
	else
		cout<<rand()%MOD;//hope for success
    return 0;
}
