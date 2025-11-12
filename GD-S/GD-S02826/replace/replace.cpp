#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main() 
{
	freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n,q;
    cin>>n>>q;
    unordered_map<int,vector<pair<string,string>>> len_rules;

    for (int i=0;i< n;++i) 
	{
        string s1,s2;
        cin>>s1>>s2;
        int len=s1.size();
        len_rules[len].emplace_back(s1, s2);
    }
    for (int i=0;i<q;++i) 
	{
        string t1,t2;
        cin>>t1>>t2;
        if(t1.size()!=t2.size()) 
		{
            cout << "0\n";
            continue;
        }
        int total=0;
        int len_t=t1.size();
        // 遍历所有可能的替换长度
        for (const auto&entry:len_rules)
		{
            int l=entry.first;
            const auto&rules=entry.second;
            if(l>len_t) continue;
            int max_pos=len_t-l;
            for(int pos=0;pos<=max_pos;++pos)
			{
                
                string sub=t1.substr(pos,l);
                for(const auto& rule:rules) 
				{
                    if (sub==rule.first) 
					{
                        string candidate=t1.substr(0,pos)+rule.second+t1.substr(pos+l);
                        if(candidate==t2) 
						{
                            total++;
                        }
                    }
                }
            }
        }
        cout<<total<<endl;
    }
    return 0;
}
