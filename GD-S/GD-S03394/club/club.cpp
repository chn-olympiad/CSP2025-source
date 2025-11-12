#include<bits/stdc++.h>
using namespace std;
int t , n , sum , r1[100010] , r2[100010] , r3[100010];
int s[100010][10];
int d1, d2, d3;
int Max(int x1 , int x2 , int x3){
	if(max(x1,max(x2,x3)) == x1) return 1;
	if(max(x1,max(x2,x3)) == x2) return 2;
	if(max(x1,max(x2,x3)) == x3) return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		sum = 0;
		d1 = d2 = d3 = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> s[i][1] >> s[i][2] >> s[i][3];
			if(Max(s[i][1],s[i][2],s[i][3]) == 1){
				r1[++d1] = i;
				sum += s[i][1];
				//cout << "+" << s[i][1] << endl;
			}else if(Max(s[i][1],s[i][2],s[i][3]) == 2){
				r2[++d2] = i;
				sum += s[i][2];
				//cout << "+" << s[i][2]<< endl;
			}else if(Max(s[i][1],s[i][2],s[i][3]) == 3){
				r3[++d3] = i;
				sum += s[i][3];
				//cout << "+" << s[i][3]<< endl;
			}
			int nx1 = 1e9 , nx2 = 1e9 , id1 , id2;
			if(d1 > n/2){
				for(int j = 1; j <= d1; j++){
					if(r1[j] != -1 && s[r1[j]][1]-s[r1[j]][2]<nx1){
						nx1 = s[r1[j]][1]-s[r1[j]][2];
						id1 = j;
					}
					if(r1[j] != -1 && s[r1[j]][1]-s[r1[j]][3]<nx2){
						nx2 = s[r1[j]][1]-s[r1[j]][3];
						id2 = j;
					}
				}
				if(d2 >= n/2 || nx1 > nx2){
					sum -= nx2;
					r3[++d3] = id2;
					r1[id2] = -1;
					d1--;
				//	cout << " " << 1 << "->" << 3 << " " << id2 << endl;
				}else{
					sum -= nx1;
					r2[++d2] = id1;
					r1[id1] = -1;
					d1--;
				//	cout << " " << 1 <<"->" << 2 <<" "<<id1 << endl;
				}
			}
			if(d2 > n/2){
				for(int j = 1; j <= d2; j++){
					if(r2[j] != -1 && s[r2[j]][2]-s[r2[j]][1]<nx1){
						nx1 = s[r2[j]][2]-s[r2[j]][1];
						id1 = j;
					}
					if(r2[j] != -1 && s[r2[j]][2]-s[r2[j]][3]<nx2){
						nx2 = s[r2[j]][2]-s[r2[j]][3];
						id2 = j;
					}
				}
				if(d1 >= n/2 || nx1 > nx2){
					sum -= nx2;
					r3[++d3] = id2;
					r2[id2] = -1;
					d2--;
				//	cout <<" " <<2 <<"->" <<3 <<" "<< id2 << endl;
				}else{
					sum -= nx1;
					r1[++d1] = id1;
					r2[id1] = -1;
					d2--;
				//	cout << " " <<2<< "->" << 1 << " "<< id1 << endl;
				}
			}
			if(d3 > n/2){
				for(int j = 1; j <= d3; j++){
					if(r3[j] != -1 && s[r3[j]][3]-s[r2[j]][1]<nx1){
						nx1 = s[r3[j]][3]-s[r3[j]][1];
						id1 = j;
					}
					if(r3[j] != -1 && s[r3[j]][3]-s[r3[j]][2]<nx2){
						nx2 = s[r3[j]][3]-s[r3[j]][2];
						id2 = j;
					}
				}
				if(d1 >= n/2 || nx1 > nx2){
					sum -= nx2;
					r2[++d2] = id2;
					r3[id2] = -1;
					d3--;
			//		cout <<" " << 3 << "->" << 2 << " "<< id2 << endl;
				}else{
					sum -= nx1;
					r1[++d1] = id1;
					r3[id1] = -1;
					d3--;
			//		cout << " " << 3 << "->" << 1<< " "<<id1 << endl;
				}
			}
		}cout << sum << endl;
	}
	return 0;
}
