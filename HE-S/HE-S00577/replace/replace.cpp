#include <iostream>
#include <map>
#include <algorithm>

int ifind(std::string raw,std::string target, int bg = 0){
    for(int i=bg;i<raw.length();i++){
        if(raw[i]==target[0]){
            for(int j=0;j<target.size();j++){
                if(raw[i+j]!=target[j]){
                    goto out;
                }
            }
            return i;
            out:
                while(0);
                // Nothing to do;
        }
    }
    return -1;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    std::map<std::string, std::string> replace_map;
    int n,q;
    std::cin >>n >>q;
    while(n--){
        std::string k,v;
        std::cin >> k >>v;
        replace_map[k] = v;
    }
    while(q--){
        std::string raw, target;
        std::cin >>raw >> target;
        int ans = 0;
        for(auto it=replace_map.begin();it!=replace_map.end();it++){
        	auto tmp = raw;
        	int bg = 0;
        	auto st = ifind(raw,it->first,bg);
        	while (st != -1){
                st = ifind(raw,it->first,bg);
                if(st != -1){
                    bg = st+1;
                    auto ed = st+it->first.size();
                    for(int i=0;st!=ed;st++,i++){raw[st] =it->second[i];}
                }
                if(raw == target)
                    ans ++;
                raw=tmp;
        	}
		}
		std::cout << ans;
    }

}
