#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct p
{
    int person = 0, club = 0, number = 0;
};

bool compare(p a, p b)
{
    //if (a.person != b.person)
    //    return a.person < b.person;
    //else
        return a.number > b.number;
}

long long tr(vector<p>& v, int n, vector<bool> join, int x, int club1, int club2, int club3)
{
    int answer = 0;
    int answer2 = 0;
    for(; x < n * 3; x++)
    {
        if (club1 + club2 + club3 == n)
        {
            break;
        }
        if (v.at(x).club == 1 && club1 >= n / 2)
        {
            continue;
        }
        if (v.at(x).club == 2 && club2 >= n / 2)
        {
            continue;
        }
        if (v.at(x).club == 3 && club3 >= n / 2)
        {
            continue;
        }
        if (join.at(v.at(x).person) == 0)
        {
            if(x + 1 < n * 3)
            {
                //answer2 = tr(v, n, join, x + 1, club1, club2, club3);
                //(v.at(x).number == v.at(x + 1).number) && 
                if ((v.at(x).number != 0) && (v.at(x + 1).number != 0))
                {
                    //if (v.at(x).person == v.at(x + 1).person)
                    //{
                        answer2 = tr(v, n, join, x + 1, club1, club2, club3);
                    //} 
                }
                
            }
            join.at(v.at(x).person) = 1;
            answer += v.at(x).number;
            if (v.at(x).club == 1)
            {
                club1++;
            }
            else if (v.at(x).club == 2)
            {
                club2++;
            }
            else
            {
                club3++;
            }
        }
    }
    return max(answer, answer2);
}

int main(int argc, char const *argv[])
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n = 1;
        cin >> n;
        vector<p> v(n * 3);
        vector<bool> join(n, 0);
        for (int i = 0,a = 0; i < n * 3; i += 3, a++)
        {
            for (int j = 0; j < 3; j++)
            {
                v.at(i + j).person = a;
                v.at(i + j).club = j + 1;
                cin >> v.at(i + j).number;
            }            
        }
        sort(v.begin(), v.end(), compare);
        long long answer = tr(v, n, join, 0, 0, 0, 0);
        cout << answer << endl;
    }
    return 0;
}
