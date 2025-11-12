#include <iostream>;
#include <string>;
#include <vector>;
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    
    vector <long long> v(10, 0);
    vector <char> number = {'0','1','2','3','4','5','6','7','8','9'};
    for (long long n = 0; n < s.size(); n++)
    {
        if (s.at(n) == '0')
        {
            v.at(0)++;
        }
        else if (s.at(n) == '1')
        {
            v.at(1)++;
        }
        else if (s.at(n) == '2')
        {
            v.at(2)++;
        }
        else if (s.at(n) == '3')
        {
            v.at(3)++;
        }
        else if (s.at(n) == '4')
        {
            v.at(4)++;
        }
        else if (s.at(n) == '5')
        {
            v.at(5)++;
        }
        else if (s.at(n) == '6')
        {
            v.at(6)++;
        }
        else if (s.at(n) == '7')
        {
            v.at(7)++;
        }
        else if (s.at(n) == '8')
        {
            v.at(8)++;
        }
        else if (s.at(n) == '9')
        {
            v.at(9)++;
        }
    }
    string answer;
    answer.erase();
    for (int i = 9; i >= 0; i--)
    {
        
        for (long long j = v.at(i); j > 0; j--)
        {
            answer += number.at(i);
        }
    }
    cout << answer << endl;
    return 0;
}
