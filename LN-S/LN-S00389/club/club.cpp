#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int f,uc,k,cc,f;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while (T){
        T--;
        int n;
        int happyz = 0;
        int shetuan1 = 0,shetuan2 = 0,shetuan3 = 0;
        cin >> n;
        int maxm = n/2+1;
        //int do1[N],do2[N],do3[N];
        for(int i = 0;i<n;i++){
            int a,b,c;
            cin >> a >> b >> c;
            int mosthappy = max(max(a,b),c);
            if (mosthappy == a){
                if(shetuan1 <= maxm){
                    happyz += a;
                    shetuan1++;
                }
                else{
                    int seco = max(b,c);
                    if (seco == b){
                        if (shetuan2 <= maxm){
                            happyz += b;
                            shetuan2++;
                        }
                        else{
                            shetuan3++;
                            happyz += c;
                        }
                    }
                }
            }
            else if (mosthappy == b){
                if(shetuan2 <= maxm){
                    happyz += b;
                    shetuan2++;
                }
                else{
                    int seco = max(a,c);
                    if (seco == a){
                        if (shetuan1 <= maxm){
                            happyz += a;
                            shetuan1++;
                        }
                        else{
                            shetuan3++;
                            happyz += c;
                        }
                    }
                }
            }
            else if (mosthappy == c){
                if(shetuan3 <= maxm){
                    happyz += c;
                    shetuan3++;
                }
                else{
                    int seco = max(a,b);
                    if (seco == a){
                        if (shetuan1 <= maxm){
                            happyz += a;
                            shetuan1++;
                        }
                        else{
                            shetuan2++;
                            happyz += b;
                        }
                    }
                }
            }
        }
        cout << happyz << endl;
    }
    return 0;
}
/*
3
4
0 1 0
1 0 0
0 0 1
1 1 1
2
1 2 1
2 1 2
3
1 0 0
0 1 0
0 0 1
*/