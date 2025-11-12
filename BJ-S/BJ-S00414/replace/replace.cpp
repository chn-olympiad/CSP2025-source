#include <iostream>

using namespace std;

struct str{
    long long afront; // a in front
    long long aend; // a in end
    long long bfront;
    long long bend;
} rules[200005];
// in rules a means from str b means to str
// in querys a means start str b means finish str
// the index of 'b' was front

signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    long long n,q;
    cin >> n >> q;
    for (long long i=0;i<n;i++)
    {
        string tmp;
        cin >> tmp;

        for(int i=0;i<tmp.length();i++)
        {
            if(tmp[i]=='b')
            {
                rules[i].afront=i;
                rules[i].aend=tmp.length()-i-1;
                
            }
        }
        cin >> tmp;
        for(int i=0;i<tmp.length();i++)
        {
            if(tmp[i]=='b')
            {
                rules[i].bfront=i;
                rules[i].bend=tmp.length()-i-1;
                
            }
        }
    }

    for (long long lzw=0;lzw<q;lzw++)
    {
        long long ans=0;
        str query;
        string tmp;
        cin >> tmp;
        for(long long i=0;i<tmp.length();i++)
        {
            if(tmp[i]=='b')
            {
                query.afront=i;
                query.aend=tmp.length()-i-1;
                
            }
        }
        cin >> tmp;
        for(long long i=0;i<tmp.length();i++)
        {
            if(tmp[i]=='b')
            {
                query.bfront=i;
                query.bend=tmp.length()-i-1;
                
            }
        }
        long long pos_of_b=query.afront-query.bfront;
        
        // + means move left
        // - means move right
        for(long long i=0;i<n;i++)
        {
            long long pos_of_i=rules[i].afront-rules[i].bfront;
            cerr << pos_of_i << endl;
            cerr << rules[i].afront << endl;
            cerr << rules[i].bfront << endl;
            
            if(pos_of_i == pos_of_b)
            {
                
                if(rules[i].afront <= query.afront && rules[i].aend <= rules[i].aend)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    
}