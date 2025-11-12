#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b;
    cin >> a >> b;
    int length = a * b;
    int grades[length + 1] = {0};
    for(int i = 0;i < length;i++){
        cin >> grades[i];
    }
    int grade = grades[0];
    int mid;
    for(int i = 0;i < length;i++){
        for(int j = 0;j < length;j++){
            if(grades[j] < grades[j + 1]){
                mid = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = mid;

            }
        }
    }
    int num;
    for(int i = 0;i < length;i++){
        if(grades[i] == grade){
            num = i;
            break;
        }
    }
    int i = 0,c,r;
    for(int m = 0;m < b;m++){
        for(int n = 0;n < a;n++){
            if(i == num){
                c = n;
                r = m;
            }
            i++;
        }
        m++;
        for(int n = a - 1;n >= 0;n--){
            if(i == num){
                c = n;
                r = m;
            }
            i++;
        }
    }
    cout << r + 1<< " " << c + 1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

