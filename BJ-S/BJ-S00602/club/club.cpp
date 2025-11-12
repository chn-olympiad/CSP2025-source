#include <bits/stdc++.h>
using namespace std;
int t,n;
bool a[3][500005];
int sum_1,sum_2,sum_3;
int num_1,num_2,num_3;
struct club_mem{
    int a,b,c;
};
club_mem c[100005];
int first_max(int i){
    if(c[i].a >= c[i].b&&c[i].a >= c[i].c){
        return 0;
    }
    else if(c[i].b >= c[i].a&&c[i].b >= c[i].c){
        return 1;
    }
    else{
        return 2;
    }
}
int first_max2(int i){
    if(c[i].a >= c[i].b&&c[i].a >= c[i].c){
        return c[i].a;
    }
    else if(c[i].b >= c[i].a&&c[i].b >= c[i].c){
        return c[i].b;
    }
    else{
        return c[i].c;
    }
}
int third_max(int i){
    if(c[i].a <= c[i].b&&c[i].a <= c[i].c){
        return 0;
    }
    else if(c[i].b <= c[i].a&&c[i].b <= c[i].c){
        return 1;
    }
    else{
        return 2;
    }
}
int second_max(int i){
    if(first_max(i) == 0&&third_max(i) == 1) return 2;
    else if(first_max(i) == 1&&third_max(i) == 2) return 0;
    else return 1;
}
int second_max2(int i){
    if(first_max(i) == 0&&third_max(i) == 1) return c[i].c;
    else if(first_max(i) == 1&&third_max(i) == 2) return c[i].a;
    else return c[i].b;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for(int q = 1;q <= t;q++){
        cin >> n;
        if(n == 2){
            long long ans;
            bool is_com = false;
            for(int i = 1;i <= 2;i++){
                cin >> c[i].a>>c[i].b>>c[i].c;

                if(first_max(i) == 0){
                    if(num_1+1 <= n/2){
                        a[0][i] = 1;
                        num_1++;
                    }
                    else{
                        is_com = true;
                        ans = max(first_max2(1)+second_max2(2),first_max2(2)+second_max2(1));
                    }
                }
                else if(first_max(i) == 1){
                    if(num_2+1 <= n/2){
                        num_2++;
                        a[1][i] = 1;
                    }
                    else{
                        is_com = true;
                        ans = max(first_max2(1)+second_max2(2),first_max2(2)+second_max2(1));
                    }
                }
                else{
                    if(num_3+1 <= n/2){
                        num_3++;
                        a[2][i] = 1;
                    }
                    else{
                        is_com = true;
                        ans = max(first_max2(1)+second_max2(2),first_max2(2)+second_max2(1));
                    }
                }
            }
            if(is_com){
                cout << ans;
            }
            else{
                for(int i = 1;i <= n;i++){
                    if(a[0][i] == 1){
                        ans += c[i].a;
                    }
                    else if(a[1][i] == 1)
                    {
                        ans += c[i].b;
                    }
                    else{
                        ans += c[i].c;
                    }
                }
                cout << ans;
            }
            return 0;
        }
        long long ans;
        for(int i = 1;i <= n;i++){
            cin >> c[i].a >> c[i].b >> c[i].c;
            if(first_max(i) == 0){
                if(num_1 <= n/2){
                    a[0][i] = 1;
                    num_1++;
                }
            }
            else if(first_max(i) == 1){
                if(num_2+1 <= n/2){
                    num_2++;
                    a[1][i] = 1;
                }
            }
            else{
                if(num_3+1 <= n/2){
                    num_3++;
                    a[2][i] = 1;
                }
            }
        }
        for(int i = 1;i <= n;i++){
            if(a[0][i] == 1){
                ans += c[i].a;
            }
            else if(a[1][i] == 1)
            {
                ans += c[i].b;
            }
            else{
                ans += c[i].c;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

