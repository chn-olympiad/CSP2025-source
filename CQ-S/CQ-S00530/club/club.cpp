#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
struct student{
	int a1,a2,a3;
};
int T,n;
struct student a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		int n2 = n / 2;
		for(int i = 1;i <= n;i++){
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		}
		
	}
	return 0;
}
