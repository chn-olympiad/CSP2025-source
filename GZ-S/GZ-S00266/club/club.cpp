//GZ-S00266 华东师范大学附属贵阳学校 杨昊宸
//思路
/*

*/
//club
#include<bits/stdc++.h> 
using namespace std;

int t;
int n;
long long answer;

struct thin{
	int num;
	int part;
};

struct people{
	thin a,b,g;
};

const int N=1e5+5;

bool cmp1(thin a,thin b);
bool cmp2(people x,people y);
people b[N];

int main(){
	//文件读写，记得去注释
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>t;
	for(int o=1;o<=t;++o){
		cin>>n;
	
		for(int i=1;i<=n;++i){
			int d=0,e=0,f=0;
			cin>>d>>e>>f;
			
			thin c[10];
			c[1].num=d;
			c[1].part=1;
			c[2].num=e;
			c[2].part=2;
			c[3].num=f;
			c[3].part=3; 
			sort(c+1,c+3+1,cmp1);
			
			b[i].a.num=c[1].num;
			b[i].a.part=c[1].part;
			b[i].b.num=c[2].num;
			b[i].b.part=c[2].part;
			b[i].g.num=c[3].num;
			b[i].g.part=c[3].part;
		}
		
		sort(b+1,b+n+1,cmp2);
		
		int h=0,k=0,l=0;
		for(int i=1;i<=n;++i){
			if(b[i].a.part==1&&h<=n/2){
				h+=1;
			}else if(b[i].a.part==2&&k<=n/2){
				k+=1;
			}else if(l<=n/2&&b[i].a.part==3){
				l+=1;
			}
		}
		
		cout<<h+k+l<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}

bool cmp1(thin a,thin b){
	if(a.num>b.num){
		return true;
	}else{
		return false;
	}
}

bool cmp2(people x,people y){
	if(x.a.num>y.a.num){
		return true;
	}else{
		return false;
	}
}
