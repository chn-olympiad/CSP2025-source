#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int n;
struct Node{
	int a,b,c;
	int x,y,z;
}student[N];
vector<int> club[4];
vector<int> num[4];
int slove(int i,int s){
	if(s == 1){
		return int(student[i].a);
	}else if(s == 2){
		return int(student[i].b);
	}else{
		return int(student[i].c);
	}
}
int fslove(int c,int num){
	if(c == 1){
		for(int i = 0;i <= n;i++){
			if(student[i].a == num) return i;
		}
	}else if(c == 2){
		for(int i = 0;i <= n;i++){
			if(student[i].b == num) return i;
		}
	}else if(c == 3){
		for(int i = 0;i <= n;i++){
			if(student[i].c == num) return i;
		}
	}
}
int rslove(int c,int num){
	for(int i = 0;i <= n;i++){
		if(club[c][i] == num) return i;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		for(int i = 0;i <= N;i++){
			student[i].a = 0;
			student[i].b = 0;
			student[i].c = 0;
			student[i].x = 0;
			student[i].y = 0;
			student[i].z = 0;
		}
		for(int i = 0;i <= 4;i++){
			club[i].clear();
			num[i].clear();
		}
		ll ans = 0;
		n = 0;
		cin >> n;
		int mxn = n / 2;
		for(int i = 1;i <= n;i++){
			int a,b,c;
			int x = 0,y = 0,z = 0;
			cin >> a >> b >> c;
			int tmp[3] = {a,b,c};
			sort(tmp,tmp+3);
			for(int j = 0;j < 3;j++){
				if(j == 0){
					if(tmp[j] == a && x != 1 && y != 1){
						z = 1;
					}else if(tmp[j] == b && x != 2 && y != 2){
						z = 2;
					}else if(tmp[j] == c && x != 3 && y != 3){
						z = 3;
					}
				}else if(j == 1){
					if(tmp[j] == a && x != 1 && z != 1){
						y = 1;
					}else if(tmp[j] == b && x != 2 && z != 2){
						y = 2;
					}else if(tmp[j] == c && x != 3 && z != 3){
						y = 3;
					}
				}else if(j == 2){
					if(tmp[j] == a && y != 1 && z != 1){
						x = 1;
					}else if(tmp[j] == b && y != 2 && z != 2){
						x = 2;
					}else if(tmp[j] == c && y != 3 && z != 3){
						x = 3;
					}
				}
			}
			student[i].a = a;
			student[i].b = b;
			student[i].c = c;
			student[i].x = x;
			student[i].y = y;
			student[i].z = z;
		}
		for(int i = 1;i <= n;i++){
			if(club[student[i].x].size() < mxn){
				club[student[i].x].push_back(i);
				num[student[i].x].push_back(slove(i,student[i].x));
				sort(num[student[i].x].begin(),num[student[i].x].end());
				ans += slove(i,student[i].x);
			}else{
				if(slove(i,student[i].x) > num[student[i].x][0]){
					ans -= num[student[i].x][0];
					club[student[i].x][rslove(student[i].x,num[student[i].x][0])] = i;
					num[student[i].x][rslove(student[i].x,num[student[i].x][0])] = i;
					sort(num[student[i].x].begin(),num[student[i].x].end());
					ans += slove(i,student[i].x);
				}else{
					if(club[student[i].y].size() < mxn){
						club[student[i].y].push_back(i);
						num[student[i].y].push_back(slove(i,student[i].y));
						sort(num[student[i].y].begin(),num[student[i].y].end());
						ans += slove(i,student[i].y);
					}else{
						if(slove(i,student[i].y) > num[student[i].y][0]){
							ans -= num[student[i].y][0];
							club[student[i].y][rslove(student[i].y,num[student[i].y][0])] = i;
							num[student[i].y][rslove(student[i].y,num[student[i].y][0])] = i;
							sort(num[student[i].y].begin(),num[student[i].y].end());
							ans += slove(i,student[i].y);
						}else{
							if(club[student[i].z].size() < mxn){
								club[student[i].z].push_back(i);
								num[student[i].z].push_back(slove(i,student[i].z));
								sort(num[student[i].z].begin(),num[student[i].z].end());
								ans += slove(i,student[i].z);
							}else{
								if(slove(i,student[i].z) > num[student[i].z][0]){
									ans -= num[student[i].z][0];
									club[student[i].z][rslove(student[i].z,num[student[i].z][0])] = i;
									num[student[i].z][rslove(student[i].z,num[student[i].z][0])] = i;
									sort(num[student[i].z].begin(),num[student[i].z].end());
									ans += slove(i,student[i].z);
								}
							}
						}
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
