#include <iostream>
#include <vector>

using namespace std;

struct Road{
    uint a, b, coins;
};

struct Bobo{
    uint coins;
    vector<uint> road_coins;
};


int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    uint n,m,k;
    // n: city, m:road, k:bobo
    cin >> n >> m >> k;

    vector<Road> roads(m);
    vector<Bobo> bobos(k);

    for(Road &r: roads){
        cin >> r.a >> r.b >> r.coins;
    }
    for(Bobo &b: bobos){
        cin >> b.coins;
        for(uint _ = 0; _ < n; _++){
            uint road_coin;
            cin >> road_coin;
            b.road_coins.push_back(road_coin);
        }
    }

    // Not true program
    
    uint coins_count = 0;
    vector<bool> used_bobo(k, false);
    for(Road road: roads){
        uint coin = road.coins;
        for(uint i = 0; i < bobos.size(); i++){
            Bobo uncity = bobos[i];
            uint bobo_coin = uncity.road_coins[road.a] 
                          + uncity.road_coins[road.b];
            if(!used_bobo[i]){
                bobo_coin += uncity.coins;
                used_bobo[i] = true;
            }
            if(bobo_coin < coin){
                coin = bobo_coin;
            }
        }
        coins_count += coin;
    }
    cout << coins_count;
    
    return 0;
}