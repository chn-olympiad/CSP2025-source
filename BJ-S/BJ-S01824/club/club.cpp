#include<iostream>

using namespace std;

int main(){
    int t;
    int n;
    int a[100005][5];
    int b[5] = {0};
    int cnt = 0;

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

    cin >> t;

    while(t){
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j =0; j < 3;j++){
                cin >> a[i][j];
            }
        }
        cnt = 0;

        for(int i = 0; i < n; i++){
            int max = a[i][0];
            b[0]++;

            for(int j =0; j < 3;j++){
                int t = 0;
                if(a[i][j] > max){
                    //while(b[j] + 1 > (n / 2)){
                    //    for()
                    //}
                    max = a[i][j];
                    b[t]--;
                    b[j]++;
                }
            }




            cnt += max;
        }





        cout << cnt << endl;
        t--;
    }





	return 0;
}
