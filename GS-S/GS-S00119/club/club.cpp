#include <bits/stdc++.h>

using namespace std;


long long const N = 1e5 +10;
int t;
long long n,a[N][3];

int main(){
    long long m = n/2;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin >> t;
	for(int s = 0; s < t; ++s){
		int ord[N][3];
		cin >>n;
		for(int i = 0 ; i < n ; i++)
        {
            cin >> a[i][0];
            cin >> a[i][1];
            cin >> a[i][2];
        }
		for(int i = 0 ; i < n ; i++ )
        {
            long long temp[3];
            temp[0] = a[i][0];
            temp[1] = a[i][1];
            temp[2] = a[i][2];
            for(int h = 0 ; h < 3; h++){
                for(int j = 0 ; j < 3 ; j++){
                    if(temp[h] < temp[j])
                    {
                        long long w=temp[j];
                        temp[h] = temp[j];
                        temp[j] = w;
                    }
                }
            }
            for(int j = 0 ; j < 3 ; j++)
            {
                for(int k = 0 ; k < 3; k++)
                {
                    if(temp[j] == a[i][k])
                    {
                        ord[i][j] = k;
                    }
                }
            }
        }
        long long ans[3]  ,cnt[3];
        for(int i = 0 ; i < 3 ; i++)
        {
            ans[i] = 0;
            cnt[i] = 0;

        }

        for(int i = 0 ; i < n ; i ++)
        {
            if(cnt[ord[i][0]] <m)
            {
                ans[ord[i][0]] += a[i][ord[i][0]];
                cnt[ord[i][0]]++;
                continue;
            }
            if(cnt[ord[i][1]] < m){
                ans[ord[i][1]] += a[i][ord[i][1]];
                cnt[ord[i][1]]++;
                continue;
            }
             if(cnt[ord[i][2]] < m){
                ans[ord[i][2]] += a[i][ord[i][2]];
                cnt[ord[i][2]]++;
                continue;
            }

        }


    cout << ans[0] + ans[1] + ans[2] << "\n";

	}

    return 0;

}

