#include<bits/stdc++.h>
using namespace std;
const int Max = 1e5 + 5;

struct WOW
{
    int n,m,Q;
    long long ant = 0;
    string Cha(int pos,string now,string to)
    {
        string res = now.substr(0,pos - 1) + to + now.substr(min(now.size() - 1,pos + to.size() + 1),now.size() - 1);
        cout <<res <<endl;
    }
    void KMP(string mo,string to,string now,string tar)
    {
        int pi[Max + Max];
        pi[0] = 0;
        pi[1] = 1;
        string owo = ' ' + mo + '&' + now;
        int lst =1;
        int tot = owo.size();
        for(int q =2;q <tot;q++)
        {
            if(owo[q] == owo[q -1])
                lst++;
            while(owo[lst] != owo[q] && (lst)  )
            {
                lst = pi[lst] + 1; 
            }
            pi[q] = lst;
            
        }
    }
    vector<pair<string,string> >num;
    void Solve()
    {
        cin >>n >>Q;
        num.resize(n +1);
        for(int q=1;q <=n;q++)
            cin >>num[q].first >>num[q].second;
        while(Q--)
        {
        	ant = 0;
            string a,aa;
            cin >>a >>aa;
            for(int q=1;q <=n;q++)
            {
                KMP(num[q].first,num[q].second,a,aa);
            }
            cout <<ant <<endl;
        }
        
    }
    void baoli()
    {
        cin >>n >>Q;
        num.resize(n +1);
        for(int q=1;q <=n;q++)
            cin >>num[q].first >>num[q].second;
        while(Q--)
        {
        	string t,tt;
        	cin >>t >>tt;
			// for(int q=1;q <=n;q++)
			// {
			// 	auto now = num[q];
			// 	for(int w=0;w <t.size();w++)
			// 	{
			// 		if(now.first[0] == t[w])
            //         {
            //             if(t.substr(w,w + now.first.size() - 1) == now.first)
            //             {
            //                 if(Cha(w,t,now.second) == tt)
            //                     ant ++;
            //             }
                        
            //         } 
			// 	}				
			// } 
            cout <<0 <<endl;
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int T = 1;
//    cin >>T;
    while(T--)
    {
        WOW OWO;
        OWO.Solve();
    }


    return 0;
}
