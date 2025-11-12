#include <iostream>
#include <vector>

struct lr {
    int l, r;
};

int max = 0;
void dfs(std::vector<lr> lrs, int index, int current){
    if (index == lrs.size()-1)
        return;
    if(current > max)
        max = current;
    for(int i=index;i<lrs.size();i++){
        if(lrs[i].l>lrs[index].r)
            dfs(lrs, i, current+1);
    }
}

std::vector<lr> pre_dfs(const std::vector<lr> &lrs){
    std::vector<lr> tmp;
    int last = lrs.begin()->l;
    tmp.push_back(lrs[0]);
    for(int i=0;i<lrs.size();i++){
        if(last == lrs[i].l)
            continue;
        tmp.push_back(lrs[i]);
        last=lrs[i].l;
    }
    return tmp;
}

int count(std::vector<int> s, int target){
    int result = 0;
    for(auto v: s){
        result += (v == target);
    }
    return result;
}

void lr_plus(std::vector<int> &t, int l, int r){
    for(int i=l;i<=r;i++){
        t[i]+=1;
    }
}

bool test(std::vector<lr>lrs, int n){
    std::vector<int>tmp(n+1,0);
    for(int i=0;i<lrs.size();i++){
        lr_plus(tmp,lrs[i].l, lrs[i].r);
    }
    
    if(count(tmp,1)+count(tmp,0) != tmp.size())
        return false;
    return true;
}

int main(){
	freopen("xor.in", "r",stdin);
	freopen("xor.out","w",stdout);

	int n,k;
	std::cin >> n >>k;

	std::vector<int> raw_data(n);
	for(auto&v:raw_data){
		std::cin >> v;
	}

	if(count(raw_data, 0) + count(raw_data,1) == n && k == 1){
        std::cout << count(raw_data, 1);
        return 0;
	}

	if(count(raw_data, 1) == n && k==0){
        std::cout << n-1;
	}

	std::vector<int> diff(n);
	diff[0]=raw_data[0];
	for(int i=1;i<n;i++){
		diff[i] = diff[i-1] ^ raw_data[i];
	}

	std::vector<lr> lrs;
	int cnt = 0;
	for(int l=0;l<n;l++){
        if(raw_data[l] == k){
            cnt++;
            lrs.push_back({l,l});
        }
		for(int r=l+1;r<n;r++){
		    int lr_xor;
		    if(l==0)
                lr_xor = diff[r];
			else
                lr_xor = diff[r] ^ diff[l-1];

            if(lr_xor == k){
                cnt ++;
                lrs.push_back({l, r});
            }
		}
	}


	if(lrs.empty()){
        std::cout << 0 << std::endl;
        return 0;
	}


	if(test(lrs,n)){
        std::cout<<cnt<<std::endl;
        return 0;
	}

	if(lrs.size() > 2000)
        lrs = pre_dfs(lrs);

    dfs(lrs,0,0);
    std::cout << max + 1 << std::endl;
    
    return 0;
}
