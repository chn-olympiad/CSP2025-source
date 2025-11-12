// Ren5Jie4Di4Ling5%

#include <bits/stdc++.h>

const int N=1*1e5+10;
const int M=3+10;

using namespace std;

int t;
int n;
pair<int,int> a[N];

bool cmp(pair<int,int> l,pair<int,int> r)
{
    return l.first>r.first;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
			int tmp,x,y;
			scanf("%d%d%d",&tmp,&x,&y);
			a[i]=make_pair(tmp,1);
        }
        sort(a+1,a+1+n,cmp);
        int sum=0;
        for(int i=1;i<=(n/2);i++)
        {
            sum+=a[i].first;
        }
        printf("%d\n",sum);
    }

    return 0;
}

/*
#include <bits/stdc++.h>

const int N=1*1e5+10;
const int M=3+10;

using namespace std;

int t;
int n;
int sum;

struct sat
{
    pair<int,int> v[M];
    int rank[M];
    bool st=false;
} f[N];

bool cmp1(sat l,sat r)
{
    return l.v[1].first>r.v[1].first;
}
bool cmp2(sat l,sat r)
{
    return l.v[2].first>r.v[2].first;
}
bool cmp3(sat l,sat r)
{
    return l.v[3].first>r.v[3].first;
}

bool cmpv(pair<int,int> l,pair<int,int> r)
{
    return l.first>r.first;
}

int max_club(sat tmp)
{
    int maxn=-1,maxi=0;
    for(int i=1;i<=3;i++)
    {
        int tmaxn=maxn;
        maxn=max(maxn,tmp.v[i].first);
        if(maxn!=tmaxn)
            maxi=i;
    }

    return maxi;
}

//#define FILENAME "club4"

int main()
{
	freopen("club4.in","r",stdin);
	freopen("club4.out","w",stdout);

    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        for(int i=0;i<N;i++)
        {
            f[i].st=false;
            f[i].v[1]=make_pair(0,1);
            f[i].v[2]=make_pair(0,2);
            f[i].v[3]=make_pair(0,3);
            memset(f[i].rank,0,sizeof(f[i].rank));
        }

        scanf("%d",&n);
        //cout<<"n="<<n<<endl;
        for(int i=1;i<=n;i++)
        {
            int tmp_a,tmp_b,tmp_c;
            scanf("%d%d%d",&tmp_a,&tmp_b,&tmp_c);
            f[i].v[1].first=tmp_a;
            f[i].v[2].first=tmp_b;
            f[i].v[3].first=tmp_c;
        }

        sort(f+1,f+n+1,cmp1);
		//int rank=1;
        for(int i=1;i<=n;i++)
        {
            f[i].rank[1]=i;
            //printf("*1*[%d]->%d***\n",i,rank);
            //if(f[i+1].v[1].first!=f[i].v[1].first)
				//rank++;
        }
        sort(f+1,f+n+1,cmp2);
        //rank=1;
        for(int i=1;i<=n;i++)
        {
            f[i].rank[2]=i;
            //printf("*2*[%d]->%d***\n",i,rank);
            //if(f[i+1].v[2].first!=f[i].v[2].first)
				//rank++;
        }
        sort(f+1,f+n+1,cmp3);
        //rank=1;
        for(int i=1;i<=n;i++)
        {
            f[i].rank[3]=i;
            //printf("*3*[%d]->%d***\n",i,rank);
            //if(f[i+1].v[3].first!=f[i].v[3].first)
				//rank++;
        }
        
        //for(int i=1;i<=n;i++)
        //{
			//printf("***f[%d]: data={(%d,%d),(%d,%d),(%d,%d); rank={%d,%d,%d}}***\n",i,f[i].v[1].first,f[i].v[1].second,f[i].v[2].first,f[i].v[2].second,f[i].v[3].first,f[i].v[3].second,f[i].rank[1],f[i].rank[2],f[i].rank[3]);
		//}

        for(int i=1;i<=n;i++)
        {
            sort(f[i].v+1,f[i].v+n+1,cmpv);
            //printf("***[%d]'s rank->%d***\n",i,f[i].rank[f[i].v[1].second]);
            if(f[i].rank[f[i].v[1].second]<=(n/2))
            {
                f[i].st=true;
                sum+=f[i].v[1].first;
            }
            else
            {
                f[i].st=true;
                sum+=f[i].v[2].first;
            }
        }

        printf("%d\n",sum);
    }

    return 0;
}
*/

/*
#include <bits/stdc++.h>

const int N=1*1e5+10;
const int M=3+10;

using namespace std;

int t;
int n;
int sum;

struct sat
{
    pair<int,int> v[M];
    int rank[M];
    bool st=false;
} f[N];

bool cmp1(sat l,sat r)
{
    return l.v[1].first>r.v[1].first;
}
bool cmp2(sat l,sat r)
{
    return l.v[2].first>r.v[2].first;
}
bool cmp3(sat l,sat r)
{
    return l.v[3].first>r.v[3].first;
}

bool cmpv(pair<int,int> l,pair<int,int> r)
{
    return l.first>r.first;
}

int max_club(sat tmp)
{
    int maxn=-1,maxi=0;
    for(int i=1;i<=3;i++)
    {
        int tmaxn=maxn;
        maxn=max(maxn,tmp.v[i].first);
        if(maxn!=tmaxn)
            maxi=i;
    }

    return maxi;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        for(int i=0;i<N;i++)
        {
            f[i].st=false;
            f[i].v[1]=make_pair(0,1);
            f[i].v[2]=make_pair(0,2);
            f[i].v[3]=make_pair(0,3);
            memset(f[i].rank,0,sizeof(f[i].rank));
        }

        scanf("&d",&n);
        for(int i=1;i<=n;i++)
        {
            int tmp_a,tmp_b,tmp_c;
            scanf("%d%d%d",&tmp_a,&tmp_b,&tmp_c);
            f[i].v[1].first=tmp_a;
            f[i].v[2].first=tmp_b;
            f[i].v[3].first=tmp_c;
        }

        sort(f+1,f+n+1,cmp1);
        for(int i=1;i<n;i++)
        {
            f[i].rank[1]=i;
        }
        sort(f+1,f+n+1,cmp2);
        for(int i=1;i<n;i++)
        {
            f[i].rank[2]=i;
        }
        sort(f+1,f+n+1,cmp3);
        for(int i=1;i<n;i++)
        {
            f[i].rank[3]=i;
        }

        for(int i=1;i<=n;i++)
        {
            sort(f[i].v+1,f[i].v+n+1,cmpv);
            if(f[i].rank[f[i].v[1].second]<=(n/2))
            {
                f[i].st=true;
                sum+=f[i].v[1].first;
            }
            else
            {
                f[i].st=true;
                sum+=f[i].v[2].first;
            }
        }

        printf("%d\n",sum);
    }

    return 0;
}
*/
