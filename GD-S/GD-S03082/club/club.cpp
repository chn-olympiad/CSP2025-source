#include<bits/stdc++.h>
using namespace std;
struct s{
	int one;
	int two;
	int three;
	int o_t;
}a[100005] = {0};
bool cmp(s x,s y){
	int o_t;
	return x.o_t > y.o_t;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	int n;
	while(T--){
		bool lll = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i].one >> a[i].two >> a[i].three;
			a[i].o_t = max(a[i].three,max(a[i].one,a[i].two));
			if(a[i].o_t == a[i].one){
				a[i].o_t = abs(a[i].o_t - max(a[i].three,a[i].two));
			}
			if(a[i].o_t == a[i].two){
				a[i].o_t = abs(a[i].o_t - max(a[i].three,a[i].one));
			}
			if(a[i].o_t == a[i].three){
				a[i].o_t = abs(a[i].o_t - max(a[i].one,a[i].two));
			}
			
        }
        sort(a+1,a+1+n,cmp);
		long long q = 0;
		int oneo = 0;
		int twot = 0;
		int threet = 0;
		for(int i = 1; i <= n; i++){
			if(max(a[i].one,a[i].two) == a[i].one && oneo <= n / 2 - 1 && a[i].one > a[i].three){
				q += a[i].one;
				oneo++;
			}else if(max(a[i].three,a[i].two) == a[i].two && twot <= n / 2-1){
				q += a[i].two;
				twot++;
			}else{
				if(threet <= n / 2-1){
					q += a[i].three;
					threet++;
				}else{
					if(a[i].two > a[i].one && twot <= n / 2-1){
						q += a[i].two;
						twot++;
					}else{
						q += a[i].one;
						oneo++;
					}
				} 
			}
		}
		cout << q << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
