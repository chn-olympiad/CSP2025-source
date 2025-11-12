// 09:01 AC this problem

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m;
int num[1005];

void Solve(int idx) {
    int row = 1;
    int line = 1;
    while(--idx) {
        if(line & 1) row++;
        else row--;
        if(row > n) line++, row--;
        if(row == 0) line++, row++;
    } cout << line << " " << row;
}

int main() 
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin >> n >> m;
    for(int i=1;i<=n*m;i++)
        cin >> num[i];
    int my_score = num[1];
    sort(num+1,num+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++)
        if(num[i] == my_score) {
            Solve(i);
            return 0;
        }
    return 0;
}