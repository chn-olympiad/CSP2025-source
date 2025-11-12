#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


bool test(vector<int> &v){
    // test if a choice can make a polygon
    int maxi=0;
    int sum=0;
    for(int i=0;i<v.size();i++){
        if(v[i]>maxi) maxi =v[i];
        sum+=v[i];
    }
    return sum>2*maxi;
}
void copy(vector<int> from, vector<int> &tow){
    for(int i=0;i<from.size();i++){
        tow[i]=from[i];
    }

}
void cout_v(vector<int>&v){
    for(int i=0;i<v.size();i++){
        cout <<v[i]<<" ";
        cout<<endl;
    }
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >>n;
    vector<int> v(n);
    for (int i = 0;i<n;i++){
        cin >> v[i];
    }
    if(n==3){
        cout<<int(test(v));
        return 0;
    }

    int count=0;

    vector<vector<int>*> all;
    vector<int> a;
    a.push_back(v[0]);
    all.push_back(&a);
    for(int j=1;j<v.size();j++){
        int all_size = all.size();
        vector<int> self;
        self.push_back(v[j]);
        all.push_back(&self);
        for(int i = 0;i<all_size;i++){
            vector<int> vi((*all[i]).size()+1);
            copy(*all[i],vi);
            vi[(*all[i]).size()]=v[j];
            all.push_back(&vi);
            if (vi.size()>=3&&test(vi)) count++;
        }
    }
    cout<<count;


    return 0;
}