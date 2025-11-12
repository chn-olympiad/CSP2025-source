#include<bits/stdc++.h>
using namespace std;

struct node{
    int l, r;
};

bool cmp(node a, node b){
    if(a.l == b.l){
        return a.r - a.l < b.r -b.l;
    }
    return a.l < b.l;
}

int _xor(int arr[], int l, int r){
    int ans = arr[l];
    for(l++; l <= r; l++){
        ans ^= arr[l];
    }
    return ans;
}

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    int n, k;
    int arr[500000] = {0};
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<node> vec, vec1;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(_xor(arr, i, j) == k){
                node a = {i, j};
                vec.push_back(a);
            }
        }
    }

    sort(vec.begin(), vec.end(), cmp);
    node s = {-1, -1};
    for(int i = 0; i < vec.size(); i++){
        if(vec[i].l > s.r){
            s = vec[i];
        }else{
            vec.erase(vec.begin() + i, vec.begin() + i + 1);
        }
    }

    cout << vec.size();


    fclose(stdin); fclose(stdout);
}

