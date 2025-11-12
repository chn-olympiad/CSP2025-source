#include<bits/stdc++.h>
using namespace std;
int t,n;
int ans[100005];
int anum  = 0, bnum = 0,cnum = 0;
int q = 0;
struct node{
	bool vis;
	int a , b ,c;
}stu[100005];
bool cmpa(node a,node b){
	return a.a > b.a;
}
bool cmpb(node a,node b){
	return a.b > b.b;
}
bool cmpc(node a,node b){
	return a.c > b.c;
}


int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		memset(stu, 0 ,sizeof(stu));
		anum  = 0, bnum = 0,cnum = 0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> stu[i].a >> stu[i].b >> stu[i].c;
		}
		sort(stu + 1,stu + 1 + n,cmpa);			
		for(int i = 1;i <= n;i++){
			if(stu[i].a > stu[i].b && stu[i].a > stu[i].c && stu[i].vis == 0){
				if(anum >= n / 2)
					break;
				stu[i].vis = 1;
				anum++;
				ans[q] += stu[i].a;
			}
		} 
		sort(stu + 1,stu + 1 + n,cmpb);			
		for(int i = 1;i <= n;i++){
			if(stu[i].b > stu[i].a && stu[i].b > stu[i].c && stu[i].vis == 0){
				if(bnum >= n / 2)
					break;
				stu[i].vis = 1;
				bnum++;
				ans[q] += stu[i].b;
			}
		} 
		sort(stu + 1,stu + 1 + n,cmpc);			
		for(int i = 1;i <= n;i++){
			if(stu[i].c > stu[i].b && stu[i].c > stu[i].a && stu[i].vis == 0){
				if(cnum >= n / 2)
					break;
				stu[i].vis = 1;
				cnum++;
				ans[q] += stu[i].c;
			}
		}
		cout << ans[q++] << endl;
	}
	return 0;
} 
