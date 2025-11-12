#include<bits/stdc++.h>
using namespace std;
vector<int> v;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0,my_point;
	cin >> n >> m >> my_point;
    v.push_back(my_point);
	for(int i=1;i<n*m;i++){
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(),v.end(),cmp);
	int x=1,y=1,downing=1;
	if(v[cnt]==my_point){
		cout << y << ' ' << x;
		return 0;
	}
	if(n==1)
		for(int i=0;i<m;i++){
			if(v[i]==my_point){
				cout << i+1 << ' ' << 1;
				return 0;
			} 
		} 
	while(cnt<=n*m){
		if(downing)x++;
		else x--;
		cnt++;
		if(v[cnt]==my_point){
			cout << y << ' ' << x;
			return 0;
		}
		if(x==n){
			downing=0;
			y++;
			cnt++;
			if(v[cnt]==my_point){
				cout << y << ' ' << x;
				return 0;
			}
			x--;
			cnt++;
			if(v[cnt]==my_point){
				cout << y << ' ' << x;
				return 0;
			}
		} 
		if(x==1){
			downing=1;
			y++;
			cnt++;
			if(v[cnt]==my_point){
				cout << y << ' ' << x;
				return 0;
			}
			x++;
			cnt++;
			if(v[cnt]==my_point){
				cout << y << ' ' << x;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
