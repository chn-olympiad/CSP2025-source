#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;


struct club{
	long long a;
	long long b;
	long long c;
};
bool ap(club a,club b){
	return a.a > b.a;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2 
10 9 8
4 0 0
 
1
4
4 2 1
3 2 4
5 3 4
3 5 1
  
1
2 
10 9 8
4 0 0

 */
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	long long abcd = 0;
	cin >> abcd;
	for(long long abc = 0;abc < abcd;abc++){
		long long n = 0;
		cin >> n;
		vector<club> vec;
		club peo = {};
		long long k = 0;
		long long l = 0;
		for(long long i = 0;i < 3*n;i++){
			if(k == 3){
				k = 0;
			}
			k++;
			cin >> peo.a;
			peo.b = k;
			if(i % 3 == 0&&i != 1){
				l++;
			}
			peo.c = l;
			vec.push_back(peo);
		}
		sort(vec.begin(),vec.end(),ap);
		long long cnt = 0;
		long long x = 0;
		for(long long i = 0;i < 3*n;i++){
			long long cn = 0;
			for(long long j = i;j < 3*n;j++){
				if(vec[i].b == vec[j].b){
					cn++;
				}
				if(cn > (n/2)){
					if(vec[i].a > vec[j].a){
						vec[j].a = 0;
					}else {
						vec[i].a = 0;
					}
				}
			}
			if(vec[i-1].c == vec[i].c||vec[i].a == 0){
				continue;
			}
			cnt += vec[i].a;
			//cout << vec[i].a << " " <<vec[i].b << " " << vec[i].c << "\n";
			x++;
			if(x == n){
				break;
			}
			
		}
		cout << cnt << "\n";
	}
	
	
	
	
	return 0;
}
