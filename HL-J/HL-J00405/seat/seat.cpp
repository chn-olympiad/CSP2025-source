#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
struct stu{
	int fenshu;
	int id;
} s[N];
bool cmp(stu a,stu b){
	return a.fenshu > b.fenshu;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int people = n*m;
	for(int i = 1;i <= people;i++){
		cin >> s[i].fenshu;
		s[i].id = i;
	}
	sort(s+1,s+people+1,cmp);
	int x = 1,y = 1;
	bool flag = true;
	for(int i = 1;i <= people;i++){
		if(s[i].id == 1){
			break;
		}
		if(x == n && flag == true){
			flag = false;
			y++;
		}else if(x == 1 && flag == false){
			flag = true;
			y++;
		}else{
			if(flag){
				x++;
			}else{
				x--;
			}
		}
		
	}
	cout << y << " "<<x;
	return 0;
}
//2 2
//99 100 97 98
//2 2
//98 99 100 97
