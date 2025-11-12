#include <bits/stdc++.h>
using namespace std;
long long n,a[5010],p[5010],cc[5010];
long long yy[5010];
bool used[5010];
const long long md = 998244353;
long long cnt = 0,sum = 0,mamm = 0;
long long mmax(long long a,long long b)
{
    if(a > b)return a;
    else return b;
}
long long jc(long long c)
{
	long long sum = 1;
	for(long long i = 1;i <= c;i++) sum *= i;
	return sum;
}
bool check(long long susm)
{
    long long mm = 0;
    for(int i = 1;i <= n;i++) if(!used[i])mm = mmax(mm,a[i]);
    if(susm - mm > mm)return true;
    else return false;
}
long long js(long long n)
{
	return (jc(p[n]) / (jc(yy[n] * jc(p[n]-yy[n]))));
}
void dfs(int step,long long susm)
{
    if(step < 4) return;
    for(int i = 1;i <= n;i++)
    {
        if(!used[i])
        {
            used[i] = 1;
            yy[a[i]]--;
            dfs(step-1,sum-a[i]);
            if(check(susm-a[i]))
            {
				
                
                cc[step-1]+=1;
                
            }
            yy[a[i]]++;
            used[i]=0;
        }
    }
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i = 1; i<=n ;i++) {p[a[i]]++;yy[a[i]]++;sum+=a[i];}
    
    dfs(n,sum);
    for(int i = 3;i <= n;i++)
    {
		cout << endl << 'a'<< i << ' ' << cc[i] << ' ' << jc(n-i) << endl;
		cnt = (cnt+cc[i]/jc(n-i+1))%md;
	}
    if(sum - a[n] > a[n])cnt = (cnt+1)%md;
    cout << cnt;
    return 0;
}
