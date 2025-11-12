#include<bits/stdc++.h>
using namespace std;

int n, t, a[100005][5], x[50005][3], y[50005][3], z[50005][3];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        int s = 0, cx = 0, cy = 0, cz = 0;
        for(int j = 1; j <= n; j ++)
        {
            cin >> a[j][1] >> a[j][2] >> a[j][3];
            if(a[j][1] >= a[j][2] and a[j][1] >= a[j][3])
            {
                if(cx * 2 < n)
                {
                    cx ++;
                    x[cx][1] = j;
                    x[cx][2] = a[j][1];
                    s += a[j][1];
                }
                else
                {
                    int m = INT_MAX, l;
                    for(int k = 1; k <= cx; k ++)
                    {
                        if(x[k][2] < m or (x[k][2] == m and max(a[x[k][1]][2], a[x[k][1]][3]) > max(a[x[l][1]][2], a[x[l][1]][3])))
                        {
                            m = x[k][2];
                            l = k;
                        }
                    }
                    if(s-m+a[j][1]+max(a[x[l][1]][2], a[x[l][1]][3]) >= s+max(a[j][2], a[j][3]))
                    {
                        s = s-m+a[j][1]+max(a[x[l][1]][2], a[x[l][1]][3]);
                        if(a[x[l][1]][2] >= a[x[l][1]][3])
                        {
                            cy ++;
                            y[cy][1] = x[l][1];
                            y[cy][2] = m;
                        }
                        else
                        {
                            cz ++;
                            z[cz][1] = x[l][1];
                            z[cz][2] = m;
                        }
                        x[l][1] = j;
                        x[l][2] = a[j][1];
                    }
                    else
                    {
                        s += max(a[j][2], a[j][3]);
                        if(a[j][2] >= a[j][3])
                        {
                            cy ++;
                            y[cy][1] = j;
                            y[cy][2] = a[j][2];
                        }
                        else
                        {
                            cz ++;
                            z[cz][1] = j;
                            z[cz][2] = a[j][3];
                        }
                    }
                }

            }
            else if(a[j][2] >= a[j][1] and a[j][2] >= a[j][3])
            {
                if(cy * 2 < n)
                {
                    cy ++;
                    y[cy][1] = j;
                    y[cy][2] = a[j][2];
                    s += a[j][2];
                }
                else
                {
                    int m = INT_MAX, l;
                    for(int k = 1; k <= cy; k ++)
                    {
                        if(y[k][2] < m or (y[k][2] == m and max(a[y[k][1]][1], a[y[k][1]][3]) > max(a[y[l][1]][1], a[y[l][1]][3])))
                        {
                            m = y[k][2];
                            l = k;
                        }
                    }
                    if(s-m+a[j][2]+max(a[y[l][1]][1], a[y[l][1]][3]) >= s+max(a[j][1], a[j][3]))
                    {
                        s = s-m+a[j][2]+max(a[y[l][1]][1], a[y[l][1]][3]);
                        if(a[y[l][1]][1] >= a[y[l][1]][3])
                        {
                            cx ++;
                            x[cx][1] = y[l][1];
                            x[cx][2] = m;
                        }
                        else
                        {
                            cz ++;
                            z[cz][1] = y[l][1];
                            z[cz][2] = m;
                        }
                        y[l][1] = j;
                        y[l][2] = a[j][2];
                    }
                    else
                    {
                        s += max(a[j][1], a[j][3]);
                        if(a[j][1] >= a[j][3])
                        {
                            cx ++;
                            x[cx][1] = j;
                            x[cx][2] = a[j][1];
                        }
                        else
                        {
                            cz ++;
                            z[cz][1] = j;
                            z[cz][2] = a[j][3];
                        }
                    }
                }

            }
            else if(a[j][3] >= a[j][1] and a[j][3] >= a[j][2])
            {
                if(cz * 2 < n)
                {
                    cz ++;
                    z[cz][1] = j;
                    z[cz][2] = a[j][3];
                    s += a[j][3];
                }
                else
                {
                    int m = INT_MAX, l;
                    for(int k = 1; k <= cz; k ++)
                    {
                        if(z[k][2] < m or (z[k][2] == m and max(a[z[k][1]][2], a[z[k][1]][1]) > max(a[z[l][1]][2], a[z[l][1]][1])))
                        {
                            m = z[k][2];
                            l = k;
                        }
                    }
                    if(s-m+a[j][3]+max(a[z[l][1]][2], a[z[l][1]][1]) >= s+max(a[j][2], a[j][1]))
                    {
                        s = s-m+a[j][3]+max(a[z[l][1]][2], a[z[l][1]][1]);
                        if(a[z[l][1]][2] > a[z[l][1]][1])
                        {
                            cy ++;
                            y[cy][1] = z[l][1];
                            y[cy][2] = m;
                        }
                        else
                        {
                            cx ++;
                            x[cx][1] = z[l][1];
                            x[cx][2] = m;
                        }
                        z[l][1] = j;
                        z[l][2] = a[j][3];
                    }
                    else
                    {
                        s += max(a[j][2], a[j][1]);
                        if(a[j][2] > a[j][1])
                        {
                            cy ++;
                            y[cy][1] = j;
                            y[cy][2] = a[j][2];
                        }
                        else
                        {
                            cx ++;
                            x[cx][1] = j;
                            x[cx][2] = a[j][1];
                        }
                    }
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}
