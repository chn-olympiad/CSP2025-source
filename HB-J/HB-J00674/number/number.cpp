#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string s;

bool cmp(int a,int b){
    return a>b;
}


int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>s;
    int n=s.size();
    vector<int> nums(1000005);
    int j=0;

    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            nums[j]=s[i]-'0';
            j++;
        }
    }

    sort(nums.begin(),nums.begin()+j,cmp);

    for(int i=0;i<j;i++){
        cout<<nums[i];
    }

    return 0;
}
