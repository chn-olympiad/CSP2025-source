#include <vector>
#include <iostream>

using namespace std;
class Road {
public:
    int price;
    int tocity;
};
class City {
public:
    vector<Road> roads;
    int index;
};
class Country {
public:
    int price;
    vector<Road> roads;
};
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    City cities[n];
    int c1, c2, p;
    for (int i = 0;i<m;i++){
        cin >> c1 >> c2 >> p;
        Road road;
        road.price = p; road.tocity = c2-1;
        cities[c1-1].index = c1-1;
        cities[c1-1].roads.push_back(road);
    }
    Country ctries[k];
    for (int i = 0;i<k;i++){
        cin >> ctries[i].price;
        for (int j = 0;j<n;j++){
            Road road;
            cin >> road.price;
            road.tocity = j;
            ctries[i].roads.push_back(road);
        }
    }

    return 0;
}
