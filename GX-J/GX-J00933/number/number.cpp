#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    int arr[1000005] = {0};
    int num = 0;
    string s;

    cin >> s;

    for (int i = 0; i < s.size(); i++){
        int c = s[i];

        if (c >= '0' && c <= '9'){
            arr[num] = c - '0';

            for (int j = num; j >= 1; j--){
                if (arr[j] >= arr[j-1])
                    swap(arr[j], arr[j-1]);

                else
                    break;
            }

            num++;
        }
    }

    for (int i = 0; i < num; i++)
        cout << arr[i];

    fclose(stdin);
    fclose(stdout);
    return 0;
}
