#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct wish{
    int target,value;
};

struct person{
    wish wishes[3]{};
};

int T;

bool cmp0(wish a,wish b)
{
    return a.value>b.value;
}
bool cmp1(person a,person b)
{
    if (a.wishes[1].value == b.wishes[1].value) return a.wishes[0].value > b.wishes[0].value;
    else return a.wishes[1].value<b.wishes[1].value;
}

void solve()
{
    person persons[100007];
    int n;
    wish popularity[3]={{0,0},{1,0},{2,0}};
    vector<vector<person>> first_wish;
    vector<person> t;
    for (int i=0;i<3;i++) first_wish.push_back(t);
    //Input and Check Popular Department
    cin>>n;
    for(int i=0;i<n;i++){
        wish wish0,wish1,wish2;
        wish0.target = 0;wish1.target = 1;wish2.target = 2;
        cin>>wish0.value>>wish1.value>>wish2.value;
        persons[i].wishes[0] = wish0;persons[i].wishes[1] = wish1;persons[i].wishes[2] = wish2;
        sort(persons[i].wishes,persons[i].wishes+3,cmp0);
        first_wish[persons[i].wishes[0].target].push_back(persons[i]);
        popularity[persons[i].wishes[0].target].value++;
    }
    sort(popularity,popularity+3,cmp0);
    //Check if over half
    int ans=0;
    if (popularity[0].value > n/2){
        //Check the secondary wish
        sort(first_wish[popularity[0].target].begin(),first_wish[popularity[0].target].end(),cmp1);
        for (int i=0; i<first_wish[popularity[0].target].size(); i++){
            person current = first_wish[popularity[0].target][i];
            if (i < n/2) ans += current.wishes[0].value;
            else ans += current.wishes[1].value;
        }
        for (int i=1; i<3; i++){
            for (int j=0;j<first_wish[popularity[i].target].size();i++){
                person current = first_wish[popularity[j].target][i];
                ans += current.wishes[0].value;
            }
        }
    } else {
        //Just sum first wish
        for(int i=0;i<n;i++){
            ans += persons[i].wishes[0].value;
        }
    }
    //put answer
    cout<<ans;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>T;
    while (T){
        T--;
        solve();
    }
}
