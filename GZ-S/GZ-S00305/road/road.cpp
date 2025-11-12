// GZ-S00305 贵阳市花溪区湖潮中学 王一帆
#include <bits/stdc++.h>
using namespace std;

bool compFixFees(vector<long> v1, vector<long> v2)
{
    if (v1[2] < v2[2])
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool compNewCitysNewRoadFees(vector<long> v1, vector<long> v2)
{
    if (v1[0] == -1)
    {
        return true;
    }
    else if (v1[1] < v2[1])
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool compNewCityFees(vector<vector<long>> v1, vector<vector<long>> v2)
{
    if (v1[0][1] < v2[0][1])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    // get data
    int orig_cities, roads, prep_villages;
    long t1, t2, t3;
    cin >> orig_cities >> roads >> prep_villages;

    // for road: city1, city2, fix_fee
    vector<vector<long>> fix_road_fees = {};
    for (int tt = 0; tt < roads; tt++)
    {
        cin >> t1 >> t2 >> t3;
        fix_road_fees.push_back({t1, t2, t3});
    }

    // // for new city: {{-1, new_city_fee}, {city, new_road_fee}, {city, new_road_fee}}
    // vector<vector<vector<long>>> new_city_fees = {};
    // for (int tt = 0; tt < prep_villages; tt++)
    // {
    //     cin >> t1;
    //     new_city_fees.push_back({{-1, t1}});
    //     for (int pp = 0; pp < orig_cities - 1; pp++)
    //     {
    //         cin >> t1;
    //         new_city_fees[tt].push_back({pp, t1});
    //     }
    // }

    // i have no idea so theres a placeholder
    for (int tt = 0; tt < prep_villages; tt++)
    {
        for (int pp = 0; pp < orig_cities; pp++)
        {
            cin >> t1;
        }
    }

    // sort fix road fees
    sort(fix_road_fees.begin(), fix_road_fees.end(), compFixFees);

    int total = 0;
    for (vector<long> fix_road_fee : fix_road_fees)
    {
        // cout << fix_road_fee[0] << " & " << fix_road_fee[1] << " : " << fix_road_fee[2] << endl;
        total += fix_road_fee[2];
    }
    cout << total;

    // // sort new city fees
    // sort(new_city_fees.begin(), new_city_fees.end(), compNewCityFees);

    // // sort new road for new city fees
    // for (int i = 0; i < new_city_fees.size(); i++)
    // {
    //     sort(new_city_fees[i].begin(), new_city_fees[i].end(), compNewCitysNewRoadFees);
    // }

    // cout << "=====" << endl;

    // for (vector<vector<long>> new_city_fee : new_city_fees)
    // {
    //     for (vector<long> new_city_road_fee : new_city_fee)
    //     {
    //         if (new_city_road_fee[0] == -1)
    //         {
    //             cout << "City build fee: " << new_city_road_fee[1] << endl;
    //         }
    //         else
    //         {
    //             cout << "  Road to city " << new_city_road_fee[0] << " fee: " << new_city_road_fee[1] << endl;
    //         }
    //     }
    // }

    return 0;
}