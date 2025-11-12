#include<bits/stdc++.h>
const int N=1e6+10;
void solve(){
    std::string s,ans;
    std::cin>>s;
    for(auto &x:s){
        if(std::isdigit(x)){
            ans.push_back(x);
        }
    }
    std::sort(ans.begin(),ans.end(),std::greater<char>());
    std::cout<<ans;
    return ;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
