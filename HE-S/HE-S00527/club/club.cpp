#include <iostream>
#include <cstring>
using namespace std;
int n,t,a[100005],b[100005],c[100005],ans,min1,type,vis[20005],ap,bp,cp;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int k = 0;k<t;k++){
		ans = 0;
		min1 = 1e9;
		memset(vis,0,sizeof(vis));
		cin >> n;
		for (int i = 0;i<n;i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		
		for (int i = 0;i<n;i++){

			if (a[i] >= b[i] && a[i] >= c[i]){
				ap++;
				ans += a[i];


			}else if (b[i] >= a[i] && b[i] >= c[i]){
				bp++;
				ans += b[i];


			}else if (c[i] >= a[i] && c[i] >= b[i]){
				cp++;
				ans += c[i];

			}
			
		}
		int All = ap + bp + cp;
		if (ap*2 <= All&&bp*2<=All&&cp*2<=All){
			cout << ans << endl;
			continue;
		}else {
			if (ap*2 > All){
				while (ap*2 > All){
					min1 = 1e9;
					for (int i = 0;i<ap;i++){
						if (b[i] - a[i] < min1 && vis[i] == false){
							min1 = a[i] - b[i];
							type = i;
						}
						if (c[i] - a[i] < min1 && vis[i] == false){
							min1 = a[i] - c[i];
							type = i;
						}
					}
					ap -= 1;
					ans -= min1;
					vis[type] = true;
				}
				
			}else if (bp*2 > All){
				while (bp*2 > All){
					min1 = 1e9;
					for (int i = 0;i<bp;i++){
						if (b[i] - c[i] < min1 && vis[i] == false){
							min1 = b[i] - c[i];
							type = i;
						}
						if (b[i] - a[i] < min1 && vis[i] == false){
							min1 = b[i] - a[i];
							type = i;
						}
					}
					bp -= 1;
					cout << min1 << endl << endl;
					ans -= min1;
					vis[type] = true;
				}
			}else if (cp*2 > All){
				while (cp*2 > All){
					min1 = 1e9;
					for (int i = 0;i<cp;i++){
						if (c[i] - a[i] < min1 && vis[i] == false){
							min1 = c[i] - a[i];
							type = i;
						}
						if (c[i] - b[i] < min1 && vis[i] == false){
							min1 = c[i] - b[i];
							type = i;
						}
					}
					cp -= 1;
					ans -= min1;
					vis[type] = true;
				}
			}
			cout << ans << endl;
		}
	}
	
	return 0;
}
