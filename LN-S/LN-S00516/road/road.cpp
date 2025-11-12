#include<bits/stdc++.h>
using namespace std;

struct wxy{
    int from;
    int to;
    int weight;
}edge[1000005];
int father[10005];
bool cmp(wxy a , wxy b){
    return a.weight < b.weight;
}
int find(int x){
    if(x == father[x]){
        return father[x];
    }else{
        father[x] = find(x);
        return father[x];
    }
}
void union_find(int x , int y){
    father[x] = find(y);
}
bool judge(int x , int y){
    if(father[x] == father[y]){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    
    int city_num , road_num , country_num;
    scanf("%d%d%d", &city_num, &road_num, &country_num);
    for(int i = 1; i <= city_num; i++){
		father[i] = i;
	}
    int ans = 0;
    if(country_num == 0){
        for(int i = 1; i <= road_num; i++){
            int wxy1 , wxy2 , wxy3;
            scanf("%d%d%d", &wxy1, &wxy2, &wxy3);
            edge[i].from = wxy1;
            edge[i].to = wxy2;
            edge[i].weight = wxy3;
        }
        sort(edge + 1 , edge + 1 + road_num , cmp);
        for(int i = 1; i <= road_num; i++){
            if(judge(edge[i].from , edge[i].to)){
                continue;
            }else{
                union_find(edge[i].from , edge[i].to);
                ans += edge[i].weight;
            }
            
        }
        printf("%d\n", ans);
    }


    
    return 0;
}
