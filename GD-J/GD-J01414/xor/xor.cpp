#include<bits/stdc++.h>
#define debug 0
#define int long long
//debug 1 -> start debug
using namespace std;
const int N = 5e5 + 10;
int n,k,a[N],arr[N];
void the_true_main(){
	//Òì»òÒª¼ÓÀ¨ºÅ£¡£¡£¡
	cin >> n >> k;
	for(int i = 1;i<= n;i++){
		cin >> a[i];
		arr[i] = arr[i - 1] ^ a[i];
	}//0 2 3 3 0
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	for(int i = n;i>= 1;i--){
		for(int j = i;j >= 1;j--){
			if((arr[i] ^ arr[j - 1]) == k){
				pq.push({i,j});
				break;
			}
		}
	} 
	int nw = -1,ans = 0;
	while(!pq.empty()){
		int l = pq.top().second,r = pq.top().first;
		//cout << l << " " << r << " ";
		pq.pop(); 
		if(l <= nw)continue;
		ans++;
		nw = r;
	}
	cout << ans;
}
signed main(){
	#if debug == 1
	cout << "start debug\n";
	#else
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	#endif
	the_true_main();
	#if debug == 0
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
} 
