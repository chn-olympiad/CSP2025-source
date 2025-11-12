#include <bits/stdc++.h>
using namespace std;
int t , n , a , a0 , a2 , a3  , n2 ,  jm [10001][4] , jk [10001][4] , lv [10001] [4] , ha , s [4] ;
long long pa [10001][10001] , mx = 0 , pm [10001][10001] ;
void qqq(int a2 , int b2 ){

        return ;
}

bool an (int x2 , int y2){
    return x2/10 > y2/10 ;
}
int main (){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t ;
    for(int i = 0 ; i < t ; i ++){
        memset(s,0,sizeof(s));
        memset(jm,0,sizeof(jm));
        memset(jm,0,sizeof(jk));
        cin >> a ;
        n2 = a / 2 ;
        for(int n = 0 ; n < a ; n ++){
            for(int x = 0 ; x < 3 ; x ++){
                cin >> ha ;
                pa[n][x] = ha*10 + x + 1 ;
                pm[n][x] = ha;
            }
            sort(pa[n] , pa[n] + 3 , an);



        }

        for(int n = 0 ; n < a ; n ++){
             /*
            for(int x = 0 ; x < 3 ; x ++){
                cout << pa[n][x] << " " ;
            }
            cout << endl ;
            // */

            if(lv[i][ pa[n][0] % 10 ] < n2 ){
                mx += pa[n][0] / 10 ;
                if(lv[i][pa[n][0] % 10] == 0){
                    jk[s[pa[n][0] % 10]][pa[n][0] % 10] = pa[n][0] / 10 ;
                    jm[s[pa[n][0] % 10]][pa[n][0] % 10] = n ;
                    s[pa[n][0] % 10]++;
                }
                else{
                    if(jk[0][pa[n][0] % 10] > pa[n][0] / 10){
                        jm[s[pa[n][0] % 10]][pa[n][0] % 10] = jm[0][pa[n][0] % 10] ;
                        jk[s[pa[n][0] % 10]][pa[n][0] % 10] = jk[0][pa[n][0] % 10] ;
                        jm[0][pa[n][0] % 10] = n ;
                        jk[0][pa[n][0] % 10] = pa[n][0] / 10 ;
                        s[pa[n][0] % 10]++;
                    }
                    else{
                        if(jk[1][pa[n][0] % 10] == pa[n][0] / 10){
                            if(pa[jm[0][pa[n][0] % 10]][1] < pa[n][1] ){
                                jm[s[pa[n][0] % 10]][pa[n][0] % 10] = jm[0][pa[n][0] % 10] ;
                                jk[s[pa[n][0] % 10]][pa[n][0] % 10] = jk[1][pa[n][0] % 10] ;
                                jm[0][pa[n][0] % 10] = n ;
                                jk[0][pa[n][0] % 10] = pa[n][0] / 10 ;
                                s[pa[n][0] % 10]++;
                            }else{
                                if(pa[jm[0][pa[n][0] % 10]][1] = pa[n][1] ){
                                    if(pa[jm[i][pa[n][0] % 10]][2] < pa[n][2] ){
                                        jm[s[pa[n][0] % 10]][pa[n][0] % 10] = jm[0][pa[n][0] % 10] ;
                                        jk[s[pa[n][0] % 10]][pa[n][0] % 10] = jk[0][pa[n][0] % 10] ;
                                        jm[0][pa[n][0] % 10] = n ;
                                        jk[0][pa[n][0] % 10] = pa[n][0] / 10 ;
                                        s[pa[n][0] % 10]++;
                                    }
                                }
                            }
                        }
                    }
                }
                lv[i][ pa[n][0] % 10 ]++ ;
            }else{
            for(int p = 0 ; p < 3 ; p ++){
                if(pa[n][p] / 10 > jk[0][pa[n][p] % 10]){
                    mx += pa[n][p] / 10;
                    mx -= jk[0][pa[n][p] % 10];
                    jk[0][pa[n][p] % 10] = pa[n][p] / 10 ;
                    jm[0][pa[n][p] % 10] = n ;

                    for(int op = 0 ; jk[op][pa[n][p] % 10] > jk[op + 1][pa[n][p] % 10]||op < s[pa[n][p] % 10] ; op ++){
                        jm[op][pa[n][p] % 10] = jm[op+1][pa[n][p] % 10] ;
                        jk[op][pa[n][p] % 10] = jk[op+1][pa[n][p] % 10] ;
                        jm[op+1][pa[n][p] % 10] = n ;
                        jk[op+1][pa[n][p] % 10] = pa[n][p] / 10 ;
                    }
                    p = 3 ;

                }else{
                    if(p<2){
                        for(int op = 0 ; op < s[pa[n][0] % 10] ; op ++){
                            if(pa[jm[op][pa[n][p] % 10]][p+1] / 10 > pa[n][p] / 10){
                                mx -= pa[jm[op][pa[n][p] % 10]][p] / 10 ;
                                mx += (pa[jm[op][pa[n][p] % 10]][p+1] / 10 ) ;
                                mx+= (pa[n][p] / 10) ;
                                //cout<<pa[jm[op][pa[n][p] % 10]][p] / 10<<" "<<(pa[jm[op][pa[n][p] % 10]][p+1] / 10 ) + (pa[n][p] / 10)<<" and "<< pa[jm[op][pa[n][p] % 10]][p+1] / 10 <<" "<<pa[n][p] / 10<<endl;
                                jk[op][pa[n][p] % 10] = pa[n][p] / 10 ;
                                jm[op][pa[n][p] % 10] = n ;
                                for(int op2 = op ; jk[op2][pa[n][p] % 10] > jk[op2 + 1][pa[n][p] % 10]&&op2 < s[pa[n][p] % 10] ; op2 ++){
                                    jm[op2][pa[n][p] % 10] = jm[op2+1][pa[n][p] % 10] ;
                                    jk[op2][pa[n][p] % 10] = jk[op2+1][pa[n][p] % 10] ;
                                    jm[op2+1][pa[n][p] % 10] = n ;
                                    jk[op2+1][pa[n][p] % 10] = pa[n][p] / 10 ;
                                }
                                op = s[pa[n][0] % 10] + 1;
                            }
                        }
                    }
                }
            }

            }
        }
        cout << mx << endl ;
        mx = 0 ;
    }

        return 0;
}
