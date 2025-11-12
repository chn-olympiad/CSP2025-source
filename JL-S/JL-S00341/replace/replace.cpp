#include<bits/stdc++.h>
using namespace std;
int n , q , cnt , ans[400010];
string s[200010][3];
map<string , int> mp;
map<int , int> qwq[200010];
vector<int> v[400010];
const int zero = 200000;
struct node
{
    int pos , id;
    bool operator < (const node &qwq) const
    {
        return pos < qwq.pos;
    } 
};
vector<node> v2[400010];
/*
void solveB()
{
   
    for(int i = 1 ; i <= q ; i ++)
    {
        int pos1 = -1 , pos2 = -1;
        string a , b; cin >> a >> b;
        for(int j = 0 ; j < a.size() ; j ++)
        {
            if(a[j] == 'b') pos1 = j;
        }
        for(int j = 0 ; j < b.size() ; j ++)
        {
            if(b[j] == 'b') pos2 = j;
        }
        // v2[pos2 - pos1 + zero].push_back((node){pos1 , i});
        // int id = lower_bound(v[pos2 - pos1 + zero].begin() , v[pos2 - pos1 + zero].end() , a.size() - pos1 + 1) - v[pos2 - pos1 + zero].begin();
        // int id2 = 
        // printf("%d\n" , id);

    }
    for(int i = 0 ; i <= zero * 2 ; i ++) sort(v2[i].begin() , v2[i].end());
    for(int i = 1 ; i <= n;  i ++)
    {
        int pos1 = -1 , pos2 = -1;
        for(int j = 0 ; j < s[i][1].size() ; j ++)
        {
            if(s[i][1][j] == 'b') pos1 = j;
        }
        for(int j = 0 ; j < s[i][2].size() ; j ++)
        {
            if(s[i][2][j] == 'b') pos2 = j;
        }
        // fuck[pos2 - pos1] ++;
        // v1[pos2 - pos1 + zero].push_back(s[i][1].size() - pos1 - 1);
        int x = pos2 - pos1 + zero;
        int id1 = upper_bound(v2[x].begin() , v2[x].end() , ({s[i][1].size() - pos1 - 1 , 0})) - v2[x].begin();
        int id2 = lower_bound(v2[x].begin() , v2[x].end() , ({pos1 , 0})) - v2[x].begin();
        int id3 = id2 - 1;
        // printf("%d\n" , (int)v2[x].size() - id1 - id3);
        for(int j = id2 ; j < id1 ; j ++)
        {
            node tmp = v2[x][j];
            ans[tmp.id] ++;
        }
    }
    for(int i = 1 ; i <= q ; i ++) printf("%d\n" , ans[i]);
}
*/
int main()
{
    freopen("replace.in" , "r" , stdin);
    freopen("replace.out" , "w" , stdout);
    scanf("%d%d" , &n , &q);
    // if()
    bool flagQ = (n <= 1000);
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> s[i][1] >> s[i][2];
        flagQ &= (s[i][1].size() <= 2000);
    }
    // if(!flagQ) solveB() , exit(0);
    for(int i = 1 ; i <= n ; i ++)
    {
        if(mp[s[i][1]] == 0) mp[s[i][1]] = ++ cnt;
        if(mp[s[i][2]] == 0) mp[s[i][2]] = ++ cnt;

        qwq[mp[s[i][1]]][mp[s[i][2]]] ++;
    }
    while(q --)
    {
        string a , b; cin >> a >> b; int pos1 = -1 , pos2 = -1;
        for(int i = 0 ; i < a.size() ; i ++)
        {
            if(a[i] != b[i])
            {
                pos1 = i;
                break;
            }
        }
        for(int i = a.size() - 1 ; i >= 0 ; i --)
        {
            if(a[i] != b[i])
            {
                pos2 = i;
                break;
            }
        }
        int anss = 0;
        string aaa = "" , bbb = "";
        for(int i = pos1 ; i <= pos2 ; i ++) aaa = aaa + a[i] , bbb = bbb + b[i]; 
        for(int i = pos1 ; i >= 0 ; i -- , aaa = a[i] + aaa , bbb = b[i] + bbb)
        {
            string nowa = aaa , nowb = bbb;
            for(int j = pos2 ; j < a.size() ; j ++ , nowa = nowa + a[j] , nowb = nowb + b[j])
            {
                // cout << nowa << "      " << nowb << endl;
                if(qwq[mp[nowa]].find(mp[nowb]) != qwq[mp[nowa]].end()) anss += qwq[mp[nowa]][mp[nowb]];
                
            }
        }
        printf("%d\n" , anss);
    }
    return 0;
}