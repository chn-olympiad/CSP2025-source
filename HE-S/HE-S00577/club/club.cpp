#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> NewPeopleData;

int solve_A(int N, int d, std::vector<NewPeopleData> new_people_data){
        std::cout << N << " " <<d<<std::endl;

    std::sort(new_people_data.begin(),new_people_data.end(),[d](NewPeopleData a, NewPeopleData b){
              return a[d]>a[d];});

    int ans = 0;
    for(int i=0;i<N/2;i++){
        ans += new_people_data[i][d];
        std::cout << "ans:" <<ans<<std::endl;

    }
    return ans;
}

int max = 0;
int counter[4];
void dfs(int N,int index, std::vector<NewPeopleData> np, int current){
    if(index == N){
        max = std::max(current, max);
        return;
    }
    for(int i=1;i<=3;i++){
        if(counter[i]==N/2)
            continue;
        counter[i]++;
        dfs(N,index+1,np,current+np[index][i]);
        counter[i]--;
    }
}

int solve_11(int N,std::vector<NewPeopleData> np){
    max = 0;
    for(int i=0;i<4;i++){
        counter[i]=0;
    }
    dfs(N,0,np,0);
    return max;
}

int main(){
    // 输入输出重定向
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    // 关闭输入输出流同步
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int testing_data_num;
    std::cin >> testing_data_num;

    while(testing_data_num--){
        int N;
        std::cin >> N;
        std::vector<NewPeopleData> np(N,std::vector<int>(4,0));
        for(auto &v:np){
            std::cin >> v[1] >>v[2] >> v[3];
        }
        {
            int tmp[4] = {0,0,0,0};
            for(auto v:np){
                tmp[1] += v[1];
                tmp[2] += v[2];
                tmp[3] += v[3];
            }
            if(tmp[2]==0 &&tmp[3]==0 ){
                std::cout <<solve_A(N,1,np);
                return 0;
            } else if(tmp[1]==0 &&tmp[3]==0 ){
                std::cout <<solve_A(N,2,np);
                return 0;
            } else if(tmp[2]==0 &&tmp[1]==0 ){
                std::cout <<solve_A(N,3,np);
                return 0;
            }
        }
        std::cout <<solve_11(N,np)<<std::endl;
    }
    return 0;
}
