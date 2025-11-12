#include <bits/stdc++.h>
using namespace std;
string a;
int b[1000001];
int main()
{
queue<string>q;
q.push(1);
strlen(cin,a);
q.push(a);
int c = q.size(),d = 0;
while(!q.empty())
{
    for(int i = 0; i <= 9; i++)
    {
        if(q.front() == i)
        {
            b[d] = q.front();
            d++;
        }
    }
    q.pop();
}
for(int j = 0; j <= d; j++)
{
    for(int i = 0; i <= d; i++)
    {
        b[i]= max(b[i],b[i+1]);
        b[i+1] = min(b[i],b[i+1]);
    }
}
for(int i = 0; i <= d; i++)
{
    cout << b[i];
}
return 0;
}
