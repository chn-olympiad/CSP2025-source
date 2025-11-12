#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    string a1[100005],a2[100005];
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a1[i] >> a2[i];
    while(m--)
    {
        int summm = 0;
        string sss1 ="";
		string sss2 = "";
        string b1,b2;
        cin >> b1>>b2;
        int e1 = b1.size(),e2 = b2.size();
        if(e1 != e2)
            cout << 0 << endl;
        else
        {
            int sum = 0;
            for (int i = 0;i < e1-1;i++)
            {
                if (b1[i] != b2[i] && b1[i+1] == b2[i+1])
                {
                    sum++;
                }
            }
            if (sum>1)
                cout << 0 << endl;
            else
            {
                for (int i = 0;i <= e1-1;i++)
                {
                    for (int j = e1-1;j > i;j--)
                    {
                        for (int k = 0;k <= i;k++)
                        {
                            sss1+=b1[k];
                            
                        }
                        for (int k = j;k <= e1;k++)
                        {
                            sss2+=b1[k];
                            
                        }
                        for (int k = 1;k <= n;k++)
                        {
                            if(sss1+a1[k]+sss2 == b2)
                            {
                            	summm++;
							}
                        }
						sss1 = "",sss2 = "";
                    }
                }
            }
        }
        cout << summm << " ";
    } 
    return 0;
}
