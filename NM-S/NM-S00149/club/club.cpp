#include<bits/stdc++.h>
using namespace std;
int t,n;
const int N = 1e5;
struct people {
	int first,second,third,maxid;
} c[N];
bool cmp(people a,people b){
	if(a.second == 0 && a.third == 0 || b.second == 0 && b.third == 0){
		return a.first < b.first;
	}else if(a.first == 0 && a.third == 0 && b.first == 0 && b.third == 0){
		return a.second > b.second;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int one = 0,two = 0,three = 0;
		int f = 0,s = 0,t = 0;
		int ave = n / 2;
		for(int i = 0; i < n; i ++) {
			c[i].maxid = INT_MIN;
		}
		for(int i = 0; i < n; i ++) {
			cin>>c[i].first>>c[i].second>>c[i].third;
			c[i].maxid = max(c[i].maxid,max(c[i].first,max(c[i].second,c[i].third)));
		}
		sort(c,c + n,cmp);
		for(int i=0; i < n; i ++) {
			if(c[i].maxid == c[i].first) {
				if(f < ave) {
					one += c[i].first;
					f++;
				}else{
					if(c[i].second >= c[i].third){
						two += c[i].second;
						s++;
					}else{
						three += c[i].third;
						t++;
					}
				}
			} else if(c[i].maxid == c[i].second) {
				if(s < ave){
					two += c[i].second;
					s++;
				}else{
					if(c[i].first >= c[i].third){
						one += c[i].first;
						f++;
					}else{
						three += c[i].third;
						t++;
					}
				} 
				
			} else {
				if(t < ave){
					three += c[i].third;
					t++;
				}else{
					if(c[i].first >= c[i].second){
						one += c[i].first;
						f++;
					}else{
						two += c[i].second;
						s++;
					}
				}
				
			}
		}
		cout<<one + two + three<<endl;
		//cout<<one<<" "<<two<<" "<<three<<endl;
	}
	return 0;
}

