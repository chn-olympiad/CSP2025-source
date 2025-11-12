#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>

int toupper(double t){
    if(t - (int)t > 0)
    {
        return (int)t+1;
    }
    return (int)t;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out", "w", stdout);

    int n,m;
    std::cin >> n>> m;

    std::vector<int> scores;
    for(int i=0; i<n*m; i++)
    {
        int tmp;
        std::cin >> tmp;
        scores.push_back(tmp);
    }

    int R_score = *scores.begin();

    std::sort(scores.begin(), scores.end(), [](int a, int b) -> bool { return a>b; });

    int R_index = 0;
    while(scores[R_index] != R_score)
    {
        R_index++;
    }
    R_index ++;

    if(toupper(R_index/(double)n)%2 == 1)
    {
        std::cout << ((R_index%n==0)?R_index/n:R_index/n+1) <<" "<< ((R_index%n == 0)?n:R_index%n);
    }
    else
    {
        std::cout << R_index/n+1 <<" "<< m - (R_index % m) + 1;
    }
    std::cout << std::endl;

    return 0;

}
