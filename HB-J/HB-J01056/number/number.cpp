#include <iostream>
#include <vector>
using namespace std;

int cnt_arr[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	vector<int> num_arr;
	for(int i = 0;i < s.size();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            num_arr.push_back(s[i] - '0');
        }
	}

	for(int i = 0;i < num_arr.size();i++){
        cnt_arr[num_arr[i]]++;
	}

    for(int i = 9;i >= 0;i--){
        while(cnt_arr[i] > 0){
            cout << i;
            cnt_arr[i]--;
        }
    }


	return 0;
}
