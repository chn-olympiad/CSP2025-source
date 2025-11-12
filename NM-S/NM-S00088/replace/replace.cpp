#include <iostream>
#include <string>

using namespace std;

struct standard{
    string from,to;
};

standard standards[200005];
int n,q;

string pos_replace(string ori,string tar,int index)
{
    for(int i=0;i<tar.size();i++){
        ori[index+i] = tar[i];
    }
    return ori;
}

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    //Input
    cin>>n>>q;
    for (int i=0;i<n;i++){
        cin>>standards[i].from>>standards[i].to;
    }
    //Solve
    while (q){
        q--;

        string raw,target;
        int ans=0;
        cin>>raw>>target;

        for (int i=0;i<n;i++){
            string from,to;
            from = standards[i].from;to = standards[i].to;
            int pos;
            pos = raw.find(from);
            if (pos < raw.size()){
                string new_str;
                new_str = pos_replace(raw,to,pos);
                if (new_str == target) ans++;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
