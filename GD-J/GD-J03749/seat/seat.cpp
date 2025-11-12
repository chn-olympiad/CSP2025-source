#include<bits/stdc++.h>
using namespace std;
int mp[105][105];
int cj[1005];
int xiaor;
int n , m;
void dfs(int x , int y , int now , bool dn , bool rwed){
//	cerr << x << ' ' << y << ' ' << cj[now] << ' ' << rwed << '\n'; 
//    if(x >n ||y >m) return;
//    if(cj[now] == xiaor){
//        cout << x <<' ' << y;
//        exit(0);
//    }
//    if(y <= m &&dn && y > 0){
//        dfs(x , y+1 , now + 1 , dn);
//    }
//    if(y <= m &&!dn && y > 0){
//        dfs(x , y-1 , now + 1 , dn);
//    }
//    if(y == m){
//        dfs(x + 1 , y , now+1 , !dn);
//    }
//    if(y == 1){
//        dfs(x + 1 , y , now + 1 , !dn);
//    }
	if(cj[now] == xiaor){
		cout << x << ' ' << y;
//		cerr << "fd::" << cj[now] << ' ' << xiaor;
		exit(0);
	}
	if(x > n || y > m){
		return;
	}
	if(x < 1 || y < 1) return;
	if(dn&& y + 1 <= m)dfs(x , y + 1 , now + 1 , dn , rwed);
	if(!dn && y - 1 > 0)dfs(x , y-1 , now + 1 , dn , rwed);
	if(!rwed && y == m){
		rwed = !rwed;
		dfs(x + 1 , y , now + 1 , !dn , !rwed);
	}
	if(y == 1 && !rwed){
		rwed = !rwed;
		dfs(x + 1 , y , now + 1 , !dn , !rwed);
	}
}
int main(){
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    cin.tie(0)->sync_with_stdio(0);

    cin >>n >>m;
    for(int i=1;i<=n *m;i++){
        cin >>cj[i];
    }
    xiaor = cj[1];
    sort(cj +1 , cj + 1 +(n *m) , [](int a , int b){return a >b ; });
//cerr << xiaor;
    dfs(1 , 1 , 1 , true , false);
}

