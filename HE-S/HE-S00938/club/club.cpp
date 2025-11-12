#include<bits/stdc++.h> 
using namespace std;

const int maxn = 1e5+5;
int t,n;

int change(int x,int y,int z){
	if (x > y){
		if (x > z) return 1;
		else if (x < z) return 3;
	}
	else {
		if (y > z) return 2;
		else if (y < z) return 3;
	}
}

int change2(int x,int y,int z){
	if (x > y){
		if (x > z){
			if (y > z) return 2;
			else return 3;
		}
		else return 1;
	}
	else {
		if (x > z) return 1;
		else{
			if (y>z) return 3;
			else return 2;	
		} 
	}
}

struct node{
	int id,st,nd;
}stu[maxn];

struct nnode{
	int minn,minn2;
}m[5];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int q = 1;q <= t;q++){
		cin >> n;
		int totx = n/2,toty = n/2,totz = n/2,sum=0;
		for (int i = 1;i <= n;i++){
			int x,y,z;
			cin >> x >> y >> z;
			stu[i].id = i;stu[i].st = change(x,y,z);stu[i].nd = change2(x,y,z);
			if(stu[i].st == 1){
				stu[i].st = x;
				if (stu[i].nd == 2) stu[i].nd = y;
				else stu[i].nd = z;
				if (totx != 0){
					sum+=x;
					if(totx == n/2){
						m[1].minn = stu[i].id;
						m[1].minn2 = stu[i].id;
					}
					else {
						if (x < stu[m[1].minn].st){
							m[1].minn2 = m[1].minn;
							m[1].minn = stu[i].id;
						}
						else if (x < stu[m[1].minn2].st) m[1].minn2 = stu[i].id;
					}
					totx--;
				}
				else if (x + stu[m[1].minn].nd > stu[m[1].minn].st){
					sum-=stu[m[1].minn].st;
					sum+=stu[m[1].minn].nd;
					sum+=x;
				}
				else {
					if (stu[i].nd == 2) sum+=y;
					else sum+=z;
				}
			}
			else if (stu[i].st == 2){
				stu[i].st = y;
				if (stu[i].nd == 1) stu[i].nd = x;
				else stu[i].nd = z;
				if (toty != 0){
					sum+=y;
					if(toty == n/2){
						m[2].minn = stu[i].id;
						m[2].minn2 = stu[i].id;
					}
					else {
						if (y < stu[m[2].minn].st) {
							m[2].minn2 = m[2].minn;
							m[2].minn = stu[i].id;
						}
						else if (y < stu[m[2].minn2].st) m[2].minn2 = stu[i].id;
					}
					toty--;
				}
				else if (y + stu[m[2].minn].nd > stu[m[2].minn].st){
					sum-=stu[m[2].minn].st;
					sum+=stu[m[2].minn].nd;
					sum+=y;
				}
				else {
					if (stu[i].nd == 1) sum+=x;
					else sum+=z;
				}
			}
			else {
				stu[i].st = z;
				if (stu[i].nd == 1) stu[i].nd = x;
				else stu[i].nd = y;
				if (totz != 0){
					sum+=z;
					if(totz == n/2){
						m[3].minn = stu[i].id;
						m[3].minn2 = stu[i].id;
					}
					else {
						if (stu[i].st < stu[m[3].minn].st){
							m[3].minn2 = m[3].minn;
							m[3].minn = stu[i].id;
						}
						else if (z < stu[m[3].minn2].st) m[3].minn2 = stu[i].id;
					}
					totz--;
				}
				else if (z + stu[m[3].minn].nd > stu[m[3].minn].st){
					sum-=stu[m[3].minn].st;
					sum+=stu[m[3].minn].nd;
					sum+=z;
				}
				else {
					if (stu[i].nd == 1) sum+=x;
					else sum+=y;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
