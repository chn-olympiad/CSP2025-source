#include <iostream>
#include <vector>
typedef std::vector<std::vector<int>> Graph;
Graph graph;
int min = 2147483646;
int vis[(int)1e5];
void dfs(std::vector<int>develop,int n, int m, int k,int cities,int current_city, int current){
    /*
    if(current < 0) {
        std::cerr << "*** MINUS! ****" <<"n: "<< n<<" m: "<< m<<" k: "<< k<<" cities: "<< cities<<" current_city: "<< current_city<<" current: "<< current << std::endl;
        std::cerr << "GRAPH" << std::endl;
        for(auto v:graph){
            for(auto g:v){
                std::cout << g << " ";
            }
            std::cout << std::endl;
        }
        std::cerr << "DEVELOP" << std::endl;
        for(auto v:develop){
            std::cout << v <<std::endl;
        }
        exit(-1);
    }*/
    // std::cerr <<"n: "<< n<<" m: "<< m<<" k: "<< k<<" cities: "<< cities<<" current_city: "<< current_city<<" current: "<< current << std::endl;
    if(cities == n){
        min = std::min(min,current);
        // std::cerr << "** RETERN! ** " <<min<<std::endl;
        return ;
    }
    for(int i = 1;i<=n+k;i++){
        if(graph[current_city][i] == -1 || vis[i])
            continue;
        vis[i]=true;
                int next_current = current + graph[current_city][i];
        if(i>n){
            for(int j=1;j<=n;j++){
                // std::cerr<<"**DEVELOP**"<<std::endl;
                // std::cerr << develop[i-n] <<" " << graph[i][j] << " " <<graph[j][i]<<std::endl;
                graph[j][i] -= develop[i-n];
                graph[i][j] -= develop[i-n];
                // std::cerr << develop[i-n] <<" " << graph[i][j] << " " <<graph[j][i]<<std::endl;
            }
        }
        int next_cities = cities;
        if(i<=n)
            next_cities++;
        dfs(develop,n,m,k,next_cities,i,next_current);
        vis[i]=false;
        if(i>n){
            for(int j=1;j<=n;j++){
                // std::cerr<<"**DEVELOP**"<<std::endl;
                // std::cerr << develop[i-n] <<" " << graph[i][j] << " " <<graph[j][i]<<std::endl;
                graph[j][i] += develop[i-n];
                graph[i][j] += develop[i-n];

                // std::cerr << develop[i-n] <<" " << graph[i][j] << " " <<graph[j][i]<<std::endl;
            }
        }
    }

    // std::cerr << "** RETERN! ** " <<cities <<" "<<current<<" "<<min<<std::endl;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int n, m, k;
    std::cin >> n >> m >> k;

    graph=Graph(n+k+1,std::vector<int>(n+k+1,-1));
    for(int i=0;i<m;i++){
        int u,v,w;
        std::cin >> u >>v >>w;
        graph[u][v]=w;
        graph[v][w]=w;
    }

    std::vector<int> develop(k+1);

    for(int i=0;i<k;i++){
        int c;
        std::cin >> c;

            develop[i+1] = c;
        for(int j=0;j<n;j++){
            int w;
            std::cin >> w;
            graph[n+i+1][j+1]=c+w;
            graph[j+1][n+1+i]=c+w;
        }
    }

    dfs(develop,n,m,k,1,1,0);
    std::cout<<min<<std::endl;

    return 0;
}
