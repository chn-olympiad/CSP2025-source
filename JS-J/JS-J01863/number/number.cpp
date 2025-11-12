#include <iostream>
#include <ios>
#include <string>
#include <queue>

bool isNumber(char c) {return c >= '0' && c <= '9';}

int main()
{
    using std::cin;
    using std::cout;
    using std::string;
    using std::priority_queue;
    cin.tie(nullptr);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string str;
    cin >> str;
    priority_queue<short> pq;
    for (int i = 0; i < str.length(); ++i)
    {
        if (isNumber(str[i]))
        {
            pq.push(str[i] - '0');
        }
    }
    while (!pq.empty())
    {
        short digit = pq.top();
        pq.pop();
        cout << digit;
    }
    cout << '\n';

    fclose(stdin);
    fclose(stdout);
    return 0;
}
