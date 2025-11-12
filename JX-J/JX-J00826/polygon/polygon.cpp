#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int a[N];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    sort(a + 1, a + n + 1);
    //if(n <= 3){
    //    if(n <= 2){
    //        cout<<"0";
    //    }else if(n == 3){
    //        if(a[1] + a[2] > a[3]){
    //            cout<<"1";
    //        }else{
    //            cout<<"0";
    //        }
    //    }
    //    return 0;
    //}
    int sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0, sum7 = 0, sum8 = 0, sum9 = 0, sum10 = 0;
    for(int i1 = 1;i1 <= n;i1++){
        for(int i2 = i1 + 1;i2 <= n;i2++){
            for(int i3 = i2 + 1;i3 <= n;i3++){
                if(a[i3] * 2 < a[i1] + a[i2] + a[i3]) sum3++, sum4++, sum5++, sum6++, sum7++, sum8++, sum9++, sum10++;
                for(int i4 = i3 + 1;i4 <= n;i4++){
                    if(a[i4] * 2 < a[i1] + a[i2] + a[i3] + a[i4]) sum4++,sum5++,sum6++,sum7++,sum8++,sum9++,sum10++;
                    for(int i5 = i4 + 1;i5 <= n;i5++){
                        if(a[i5] * 2 < a[i1] + a[i2] + a[i3] + a[i4] + a[i5]) sum5++,sum6++,sum7++,sum8++,sum9++,sum10++;
                        for(int i6 = i5 + 1;i6 <= n;i6++){
                            if(a[i6] * 2 < a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6]) sum6++,sum7++,sum8++,sum9++,sum10++;
                            for(int i7 = i6 + 1;i7 <= n;i7++){
                                if(a[i7] * 2 < a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7]) sum7++,sum8++,sum9++,sum10++;
                                for(int i8 = i7 + 1;i8 <= n;i8++){
                                    if(a[i8] * 2 < a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8]) sum8++,sum9++,sum10++;
                                    for(int i9 = i8 + 1;i9 <= n;i9++){
                                        if(a[i9] * 2 < a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8] + a[i9]) sum9++,sum10++;
                                        for(int i10 = i9 + 1;i10 <= n;i10++){
                                            if(a[i10] * 2 < a[i1] + a[i2] + a[i3] + a[i4] + a[i5] + a[i6] + a[i7] + a[i8] + a[i9] + a[i10]) sum10++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(n <= 2){
        cout<<"0";
        return 0;
    }
    if(n == 3){
        cout<<sum3;
    }else if(n == 4){
        cout<<sum4;
    }else if(n == 5){
        cout<<sum5;
    }else if(n == 6){
        cout<<sum6;
    }else if(n == 7){
        cout<<sum7;
    }else if(n == 8){
        cout<<sum8;
    }else if(n == 9){
        cout<<sum9;
    }else if(n == 10){
        cout<<sum10;
    }
    return 0;
}
