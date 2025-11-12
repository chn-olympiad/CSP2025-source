#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int city[1005][1005];
struct C
{
    int u,v,value;
}City[1000005];
int a[10][1005];
bool visited[1000005];

bool cmp(C x,C y)
{
    return x.value < y.value;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,S;
        cin >> u >> v >> S;
        city[u][v] = S;
        city[v][u] = S;
    }
    for (int i = 1;i <= k;i++)
    {
        cin >> a[i][0];
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
        }
        for (int I = 1;I <= n;I++)
        {
            for (int J = I+1;J <= n;J++)
            {
                if (a[i][0]+a[i][I]+a[i][J]<city[I][J] || city[I][J]==0) city[I][J] = a[i][0]+a[i][I]+a[i][J];
            }
        }
    }
    int pos = 1,I=0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = i+1;j <= n;j++)
        {
            I++;
            City[I].u=i;
            City[I].v=j;
            City[I].value=city[i][j];
        }
    }
    sort(City+1,City+I+1,cmp);
    int sum = 0,ans = 0;
    visited[City[1].u] = 1;
    for (int i = 1;i <= I;i++)
    {
        if (!visited[City[i].u]||!visited[City[i].v])
        {
            sum+=1;
            visited[City[i].u]=1;
            visited[City[i].v]=1;
            ans+=City[i].value;
        }
        if (sum==n) break;
    }
    cout << ans;
    return 0;
}