#include<bits/stdc++.h>
using namespace std;
struct st{
	int a,b,c,want;
};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		st stu[n];
		int x=0,y=0,z=0;
		int x1[n];
		char x2[n];
		int y1[n];
		char y2[n];
		for(int i=0;i<n;i++){
			cin >> stu[i].a >> stu[i].b >> stu[i].c;
			//int maxn=INTMIN;
			int a1[3]={stu[i].a,stu[i].b,stu[i].c};
			int b1[3]={stu[i].a,stu[i].b,stu[i].c};
			sort(a1,a1+3,cmp);
			stu[i].a=a1[0];
			stu[i].b=a1[1];
			stu[i].c=a1[2];
			int zz=0;
			for(int j=0;j<3;j++){
				if(a1[0]==b1[j]){
					if(j+1==1){
						x++;
						zz++;
					}else if(j+1==2){
						y++;
					}else if(j+1==3){
						z++;
					}
				}
			}
			x1[i]=stu[i].b;
			for(int j=0;j<3;j++){
				if(a1[1]==b1[j] && zz!=0){
					if(j+1==1){
						x2[i]='1';
					}else if(j+1==2){
						x2[i]='2';
					}else if(j+1==3){
						x2[i]='3';
					}
				}
			}
			y1[i]=stu[i].c;
			for(int j=0;j<3;j++){
				if(a1[2]==b1[j] && zz!=0){
					if(j+1==1){
						y2[i]='1';
					}else if(j+1==2){
						y2[i]='2';
					}else if(j+1==3){
						y2[i]='3';
					}
				}
			}
		}
		sort(x1,x1+n,cmp);
		sort(x2,x2+n,cmp);
		if(x>n/2){
			int sum=0;
			for(int i=0;i<n;i++){
				if(sum<=x-n/2){
				if(x2[i]==2 && y++<=n/2){
					stu[i].a=stu[i].b;
				}else if(x2[i]==2 && z++<=n/2){
					stu[i].a=stu[i].c;
				}else{
					continue;
				}sum++; 
			}
			}
		}
		int total=0;
		for(int i=0;i<n;i++){
			total+=stu[i].a;
		}
		cout << total << endl; 
	}
	return 0;
}
