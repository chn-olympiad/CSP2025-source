#include<bits/stdc++.h>
using namespace std;
struct student{
	int a,b,c;
	int choose,choose2;
	int choosenum,choose2num;
	int gapp;
	bool operator<(const student&other ) const{
		return gapp>other.gapp;
	}
};
student s[200005];
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	scanf("%d",&t);
	while(t--){
		memset(s,0,sizeof(0));
		int n;
		cin>>n;
		priority_queue<student> map1,map2,map3;
		long long res1=0;
		long long res2=0;
		long long res3=0;
			for(int i=1;i<=n;i++){
				int x,y,z;
				scanf("%d",&x);
				int point=1; int pointnum=x; int point2,point2num;
				scanf("%d",&y); if(y>pointnum){point=2;pointnum=y;}
				scanf("%d",&z); if(z>pointnum){point=3;pointnum=z;}
				if(point==1){
					if(y>z) {point2=2;point2num=y;}
					else {point2=3;point2num=z;}
				} else if(point==2){
					if(x>z) {point2=1;point2num=x;}
					else {point2=3;point2num=z;}
				}else{
					if(x>y) {point2=1;point2num=x;}
					else {point2=2;point2num=y;}
				}
				s[i].choose=point; s[i].choosenum=pointnum;
				s[i].choose2=point2; s[i].choose2num=point2num;
				s[i].gapp=(s[i].choosenum-s[i].choose2num);
				if(s[i].choose==1) {map1.push(s[i]),res1+=s[i].choosenum;}
				else if(s[i].choose==2) {map2.push(s[i]),res2+=s[i].choosenum;}
				else {map3.push(s[i]),res3+=s[i].choosenum;}
			}
			int ress=res1+res2+res3;
			if((map1.size()<=(n/2))&&(map2.size()<=(n/2))&&(map3.size()<=(n/2))){
				printf("%d",ress);
			}else if(map1.size()>(n/2)){
				int c=map1.size()-(n/2);
				while(c--){
					ress-=(map1.top().gapp);
					map1.pop();
				}
				printf("%d",ress);
			}else if(map2.size()>(n/2)){
				int c=map2.size()-(n/2);
				while(c--){
					ress-=(map2.top().gapp);
					map2.pop();
				}
				printf("%d",ress);
		    }else {
				int c=map3.size()-(n/2);
				while(c--){
					ress-=(map3.top().gapp);
					map3.pop();
				}
				printf("%d",ress);
		    }
		cout<<endl; 
	}
    return 0;
} 