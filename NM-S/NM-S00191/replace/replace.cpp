#include <iostream>

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    std::cin >> n >> q;
    std::string s[n][2], t[q][2];
    for (int i = 0; i < n; i++)
    {
        std::cin >> s[i][1] >> s[i][2];
    }
    for (int i = 0; i < q; i++)
    {
        std::cin >> t[i][1] >> t[i][2];
    }
    for (int i = 0; i < q; i++)
    {
        for (int i = 0; i < t[n][1].length(); i++)
        {
            for (int i = 0; i < ; i++)
            {
                /* code */
            }
            
        }
        
    }

    fclose(stdout);
    fclose(stdin);
    return 0;
}