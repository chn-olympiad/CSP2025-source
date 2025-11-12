#include <bits/stdc++.h>
using namespace std;

struct node{
	int a,b,c,mx;
	bool operator<(node &an){
		return  2 * mx - a - b - c < 2 * an.mx - an.a - an.b - an.c;
	}
};
node arr[100010];
int t,n,a,b,c;
long long ans;


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		
		for(int i = 1;i <= n;i++) arr[i] = {0,0,0};
		ans = 0;a = 0;b = 0;c = 0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> arr[i].a >> arr[i].b >> arr[i].c;
			arr[i].mx = max(arr[i].a,max(arr[i].b,arr[i].c));
		}
		sort(arr + 1,arr + 1 + n);
		
		for(int i = n;i >= 1;i--){
			if(arr[i].a > arr[i].b && arr[i].a > arr[i].c && a < n / 2){
				ans += arr[i].a;
				a++;
				//cout << arr[i].a << endl;
			}else{
				if(arr[i].b > arr[i].c && b < n / 2){
					ans += arr[i].b;
					b++;
					//cout << arr[i].b << endl;
				}else{
					if(c < n / 2){
						c++;
						ans += arr[i].c;
						//cout << arr[i].c << endl;
					}else{
						ans += max(arr[i].a,arr[i].b);
						//cout << max(arr[i].a,arr[i].b) << endl;
					}
				}
			}
		}
		
		cout << ans << endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
