#include <iostream>
#include <vector>
#include <algorithm>

int dfs(int deep,int deep_max,std::vector<int>v,int index,int current, int current_max){
	if(deep>deep_max)
		return 0;
	int result = 0;
	for(int i=index+1;i<v.size();i++){
				int next_current_max = current_max;
		if(v[i]>current_max)
			next_current_max = v[i];
		
		if(deep == deep_max && current + v[i] > 2*next_current_max){
			result ++;
			continue;
		}
		

		
		result += dfs(deep+1,deep_max,v,i,current+v[i],next_current_max);
	}
	
	return result% 998244353;
}

int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out", "w", stdout);
    
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	for(auto &v:a){
		std::cin >> v; 
	} 
	
	int ans = 0;
	for(int s = 3;s<=n;s++){
		ans += dfs(1,s,a,-1,0,0);
	}
	
	std::cout << ans % 998244353;
	
	return 0;
}
