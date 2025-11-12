#include <bits/stdc++.h>
using namespace std;
long long vis[100200];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        vector<int> a,b,c;
        int n;
        cin >> n;
        long long n1 = 0,n2 = 0,n3 = 0,ans = 0;
        for(int i = 1;i <= n;i++){
            int x,y,z;
            cin >> x >> y >> z;
            int p;
            if(x >= max(y,z)) p = min(x - y,x - z);
            else if(y >= max(x,z)) p = min(y - x,y - z);
            else p = min(z - x,z - y);
            ans += max(x,max(y,z));
            vis[i] = p;
            if(x >= max(y,z)){
                a.push_back(i);
                n1++;
            }
            else if(y >= max(x,z)){
                b.push_back(i);
                n2++;
            }
            else{
                c.push_back(i);
                n3++;
            }
        }
        if(n1 <= n / 2 && n2 <= n / 2 && n3 <= n / 2) cout << ans << endl;
        else{
        	if(n1 > n / 2){
        		int temp[100200];
        		for(int i = 0;i < a.size();i++) temp[i] = vis[a[i]];
        		sort(temp,temp + a.size());
        		for(int i = 0;i < a.size() - n / 2;i++) ans -= temp[i];
			}
			else if(n2 > n / 2){
				int temp[100200];
        		for(int i = 0;i < b.size();i++) temp[i] = vis[b[i]];
        		sort(temp,temp + b.size());
        		for(int i = 0;i < b.size() - n / 2;i++) ans -= temp[i];
			}
			else if(n3 > n / 2){
				int temp[100200];
        		for(int i = 0;i < c.size();i++) temp[i] = vis[c[i]];
        		sort(temp,temp + c.size());
        		for(int i = 0;i < c.size() - n / 2;i++) ans -= temp[i];
			}
			cout << ans << endl;
		}
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
